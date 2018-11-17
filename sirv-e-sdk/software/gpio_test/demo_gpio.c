// See LICENSE for license details.

#include <stdio.h>
#include <stdlib.h>
#include "platform.h"
#include <string.h>
#include "plic/plic_driver.h"
#include "encoding.h"
#include <unistd.h>
#include "stdatomic.h"

#include "per_gpio.h"
#include "per_pwm.h"

pwm_pin_t pwm_red, pwm_green, pwm_blue;
pwm_global_t pwm_settings;
gpio_pin_t red_led, blue_led, green_led;

// Structures for registering different interrupt handlers
// for different parts of the application.
typedef void (*function_ptr_t) (void);

void no_interrupt_handler (void) {};

function_ptr_t g_ext_interrupt_handlers[PLIC_NUM_INTERRUPTS];


// Instance data for the PLIC.

plic_instance_t g_plic;


volatile uint32_t delay_ms_cnt = 0;

/*Entry Point for PLIC Interrupt Handler*/
void handle_m_ext_interrupt(){
  plic_source int_num  = PLIC_claim_interrupt(&g_plic);
  if ((int_num >=1 ) && (int_num < PLIC_NUM_INTERRUPTS)) {
    g_ext_interrupt_handlers[int_num]();
  }
  else {
    exit(1 + (uintptr_t) int_num);
  }
  PLIC_complete_interrupt(&g_plic, int_num);
}


/*Entry Point for Machine Timer Interrupt Handler*/
void handle_m_time_interrupt(){

  clear_csr(mie, MIP_MTIP);

  // Reset the timer for 1ms in the future.
  // This also clears the existing timer interrupt.
  volatile uint64_t * mtime       = (uint64_t*) (CLINT_CTRL_ADDR + CLINT_MTIME);
  volatile uint64_t * mtimecmp    = (uint64_t*) (CLINT_CTRL_ADDR + CLINT_MTIMECMP);
  uint64_t now = *mtime;
  uint64_t then = now + (RTC_FREQ/1000);
  *mtimecmp = then;

  delay_ms_cnt++;
  
  // Re-enable the timer interrupt.
  set_csr(mie, MIP_MTIP);

}

static void delay_ms(uint32_t delay)
{
  uint32_t now = 0;
  now = delay_ms_cnt + delay;
  while(now > delay_ms_cnt);
}

void reset_demo ()
{
  // Disable the machine & timer interrupts until setup is done.
  clear_csr(mie, MIP_MEIP);
  clear_csr(mie, MIP_MTIP);

  for (int ii = 0; ii < PLIC_NUM_INTERRUPTS; ii ++){
    g_ext_interrupt_handlers[ii] = no_interrupt_handler;
  }

    // Set the machine timer to go off in 1 millisecond.
    volatile uint64_t * mtime       = (uint64_t*) (CLINT_CTRL_ADDR + CLINT_MTIME);
    volatile uint64_t * mtimecmp    = (uint64_t*) (CLINT_CTRL_ADDR + CLINT_MTIMECMP);
    uint64_t now = *mtime;
    uint64_t then = now + (RTC_FREQ/1000);
    *mtimecmp = then;

    // Enable the Machine-External bit in MIE
    set_csr(mie, MIP_MEIP);

    // Enable the Machine-Timer bit in MIE
    set_csr(mie, MIP_MTIP);

    // Enable interrupts in general.
    set_csr(mstatus, MSTATUS_MIE);
}

int main(int argc, char **argv)
{

  /**************************************************************************
   * Set up the PLIC
   *
   *************************************************************************/
  PLIC_init(&g_plic,
	    PLIC_CTRL_ADDR,
	    PLIC_NUM_INTERRUPTS,
	    PLIC_NUM_PRIORITIES);


  reset_demo();
  printf("Hello world from Lichee Tang!\n");

  
  red_led.pin = 1;
  red_led.direction = GPIO_DIRECTION_OUT;
  red_led.mode = GPIO_GPIO_MODE;
  red_led.invert = GPIO_INVERT_ENABLE;  //RGB leds are on when output is low, so invert here.
  per_gpio_setup(red_led);
  
  blue_led.pin = 2;
  blue_led.direction = GPIO_DIRECTION_OUT;
  blue_led.mode = GPIO_GPIO_MODE;
  blue_led.invert = GPIO_INVERT_ENABLE;
  per_gpio_setup(blue_led);
  
  green_led.pin = 3;
  green_led.direction = GPIO_DIRECTION_OUT;
  green_led.mode = GPIO_GPIO_MODE;
  green_led.invert = GPIO_INVERT_ENABLE;
  per_gpio_setup(green_led);
 
  per_gpio_write(red_led, GPIO_OFF);
  per_gpio_write(blue_led, GPIO_OFF);
  per_gpio_write(green_led, GPIO_OFF);

  while(1)
  {
    per_gpio_write(red_led, GPIO_ON);
    delay_ms(250);
    per_gpio_write(red_led, GPIO_OFF);
    delay_ms(250);
    per_gpio_write(blue_led, GPIO_ON);
    delay_ms(250);
    per_gpio_write(blue_led, GPIO_OFF);
    delay_ms(250);
    per_gpio_write(green_led, GPIO_ON);
    delay_ms(250);
    per_gpio_write(green_led, GPIO_OFF);
    delay_ms(250);
  }
  return 0;

}

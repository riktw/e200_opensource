#ifndef _PER_GPIO_H
#define _PER_GPIO_H

#include <stdint.h>

#define GPIO_ON             1
#define GPIO_OFF            0
#define GPIO_DRIVE_HIGH		1
#define GPIO_DRIVE_LOW		0
#define GPIO_DIRECTION_OUT	1
#define GPIO_DIRECTION_IN	0
#define GPIO_PULLUP_ENABLE	1
#define GPIO_PULLUP_DISABLE 0
#define GPIO_ALT_MODE		1
#define GPIO_GPIO_MODE		0
#define GPIO_ALT0			0
#define GPIO_ALT1			1
#define GPIO_INVERT_ENABLE	1
#define GPIO_INVERT_DISABLE	0


typedef struct
{
	uint8_t pin;
	uint8_t direction;
	uint8_t pull;
	uint8_t drive;
	uint8_t mode;
	uint8_t select_alt;
	uint8_t invert;
}gpio_pin_t;

void per_gpio_setup(gpio_pin_t pin_settings);
uint8_t per_gpio_read(gpio_pin_t pin_settings);
void per_gpio_write(gpio_pin_t pin_settings, uint8_t value);
void per_gpio_toggle(gpio_pin_t pin_settings);

#endif

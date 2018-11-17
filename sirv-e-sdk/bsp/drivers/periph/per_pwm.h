#ifndef _PER_PWM_H
#define _PER_PWM_H

#include <stdint.h>

#define PWM_ALIGNMENT_CENTER	1
#define PWM_ALIGNMENT_RIGHT		0
#define PWM_MODE_ONESHOT		1
#define PWM_MODE_ALWAYS_ON		0


typedef struct
{
	uint8_t block;
	uint8_t pin;
	uint8_t alignment;
	uint16_t compare;
} pwm_pin_t;

typedef struct
{
	uint8_t block;
	uint8_t mode;
	uint8_t clockdiv;
	uint16_t countval;
} pwm_global_t;

void per_pwm_global_setup(pwm_global_t pwm_settings);
void per_pwm_pin_setup(pwm_pin_t pin_settings);

#endif

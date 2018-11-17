#include "per_pwm.h"
#include "platform.h"

void per_pwm_global_setup(pwm_global_t pwm_settings)
{
	if(pwm_settings.block == 0)
	{
		if(pwm_settings.mode == PWM_MODE_ONESHOT)
		{
			PWM0_REG(PWM_CFG) |= PWM_CFG_ONESHOT;
			PWM0_REG(PWM_CFG) &= ~PWM_CFG_ENALWAYS;
		}
		else
		{
			PWM0_REG(PWM_CFG) &= ~PWM_CFG_ONESHOT;
			PWM0_REG(PWM_CFG) |= PWM_CFG_ENALWAYS;
		}
		PWM0_REG(PWM_CFG) &= ~0xF;
		PWM0_REG(PWM_CFG) |= (pwm_settings.clockdiv & 0xf);
		PWM0_REG(PWM_COUNT) = pwm_settings.countval;
	}
	else if(pwm_settings.block == 1)
	{
		if(pwm_settings.mode == PWM_MODE_ONESHOT)
		{
			PWM1_REG(PWM_CFG) |= PWM_CFG_ONESHOT;
			PWM1_REG(PWM_CFG) &= ~PWM_CFG_ENALWAYS;
		}
		else
		{
			PWM1_REG(PWM_CFG) &= ~PWM_CFG_ONESHOT;
			PWM1_REG(PWM_CFG) |= PWM_CFG_ENALWAYS;
		}
		PWM1_REG(PWM_CFG) &= ~0xF;

		PWM1_REG(PWM_CFG) |= (pwm_settings.clockdiv & 0xf);
		PWM1_REG(PWM_COUNT) = pwm_settings.countval;
	}
	else if(pwm_settings.block == 2)
	{
		if(pwm_settings.mode == PWM_MODE_ONESHOT)
		{
			PWM2_REG(PWM_CFG) |= PWM_CFG_ONESHOT;
			PWM2_REG(PWM_CFG) &= ~PWM_CFG_ENALWAYS;
		}
		else
		{
			PWM2_REG(PWM_CFG) &= ~PWM_CFG_ONESHOT;
			PWM2_REG(PWM_CFG) |= PWM_CFG_ENALWAYS;
		}
		PWM2_REG(PWM_CFG) &= ~0xF;
		PWM2_REG(PWM_CFG) |= (pwm_settings.clockdiv & 0xf);
		PWM2_REG(PWM_COUNT) = pwm_settings.countval;
	}
}

void per_pwm_pin_setup(pwm_pin_t pin_settings)
{
	if(pin_settings.block == 0)
	{	
		if(pin_settings.pin == 0)
		{
			PWM0_REG(PWM_CMP0) = pin_settings.compare;
			if(pin_settings.alignment)
			{
				PWM0_REG(PWM_CFG) |= PWM_CFG_CMP0CENTER;
			}
			else
			{
				PWM0_REG(PWM_CFG) &= ~PWM_CFG_CMP0CENTER;
			}
		}
		else if(pin_settings.pin == 1)
		{
			PWM0_REG(PWM_CMP1) = pin_settings.compare;
			if(pin_settings.alignment)
			{
				PWM0_REG(PWM_CFG) |= PWM_CFG_CMP1CENTER;
			}
			else
			{
				PWM0_REG(PWM_CFG) &= ~PWM_CFG_CMP1CENTER;
			}
		}
		else if(pin_settings.pin == 2)
		{
			PWM0_REG(PWM_CMP2) = pin_settings.compare;
			if(pin_settings.alignment)
			{
				PWM0_REG(PWM_CFG) |= PWM_CFG_CMP2CENTER;
			}
			else
			{
				PWM0_REG(PWM_CFG) &= ~PWM_CFG_CMP2CENTER;
			}
		}
		else if(pin_settings.pin == 3)
		{
			PWM0_REG(PWM_CMP3) = pin_settings.compare;
			if(pin_settings.alignment)
			{
				PWM0_REG(PWM_CFG) |= PWM_CFG_CMP3CENTER;
			}
			else
			{
				PWM0_REG(PWM_CFG) &= ~PWM_CFG_CMP3CENTER;
			}
		}
	}
	else if(pin_settings.block == 1)
	{
	if(pin_settings.pin == 0)
		{
			PWM1_REG(PWM_CMP0) = pin_settings.compare;
			if(pin_settings.alignment)
			{
				PWM1_REG(PWM_CFG) |= PWM_CFG_CMP0CENTER;
			}
			else
			{
				PWM1_REG(PWM_CFG) &= ~PWM_CFG_CMP0CENTER;
			}
		}
		else if(pin_settings.pin == 1)
		{
			PWM1_REG(PWM_CMP1) = pin_settings.compare;
			if(pin_settings.alignment)
			{
				PWM1_REG(PWM_CFG) |= PWM_CFG_CMP1CENTER;
			}
			else
			{
				PWM1_REG(PWM_CFG) &= ~PWM_CFG_CMP1CENTER;
			}
		}
		else if(pin_settings.pin == 2)
		{
			PWM1_REG(PWM_CMP2) = pin_settings.compare;
			if(pin_settings.alignment)
			{
				PWM1_REG(PWM_CFG) |= PWM_CFG_CMP2CENTER;
			}
			else
			{
				PWM1_REG(PWM_CFG) &= ~PWM_CFG_CMP2CENTER;
			}
		}
		else if(pin_settings.pin == 3)
		{
			PWM1_REG(PWM_CMP3) = pin_settings.compare;
			if(pin_settings.alignment)
			{
				PWM1_REG(PWM_CFG) |= PWM_CFG_CMP3CENTER;
			}
			else
			{
				PWM1_REG(PWM_CFG) &= ~PWM_CFG_CMP3CENTER;
			}
		}
	}
	else if(pin_settings.block == 2)
	{
	if(pin_settings.pin == 0)
		{
			PWM2_REG(PWM_CMP0) = pin_settings.compare;
			if(pin_settings.alignment)
			{
				PWM2_REG(PWM_CFG) |= PWM_CFG_CMP0CENTER;
			}
			else
			{
				PWM2_REG(PWM_CFG) &= ~PWM_CFG_CMP0CENTER;
			}
		}
		else if(pin_settings.pin == 1)
		{
			PWM2_REG(PWM_CMP1) = pin_settings.compare;
			if(pin_settings.alignment)
			{
				PWM2_REG(PWM_CFG) |= PWM_CFG_CMP1CENTER;
			}
			else
			{
				PWM2_REG(PWM_CFG) &= ~PWM_CFG_CMP1CENTER;
			}
		}
		else if(pin_settings.pin == 2)
		{
			PWM2_REG(PWM_CMP2) = pin_settings.compare;
			if(pin_settings.alignment)
			{
				PWM2_REG(PWM_CFG) |= PWM_CFG_CMP2CENTER;
			}
			else
			{
				PWM2_REG(PWM_CFG) &= ~PWM_CFG_CMP2CENTER;
			}
		}
		else if(pin_settings.pin == 3)
		{
			PWM2_REG(PWM_CMP3) = pin_settings.compare;
			if(pin_settings.alignment)
			{
				PWM2_REG(PWM_CFG) |= PWM_CFG_CMP3CENTER;
			}
			else
			{
				PWM2_REG(PWM_CFG) &= ~PWM_CFG_CMP3CENTER;
			}
		}
	}
}


#include "per_gpio.h"
#include "platform.h"

void per_gpio_setup(gpio_pin_t pin_settings)
{
	if(pin_settings.direction == 0)
	{
		GPIO_REG(GPIO_OUTPUT_EN) &= ~(0x1<< pin_settings.pin);
		GPIO_REG(GPIO_INPUT_EN) |= (0x1<< pin_settings.pin);
	}
	else
	{
		GPIO_REG(GPIO_INPUT_EN) &= ~(0x1<< pin_settings.pin);
		GPIO_REG(GPIO_OUTPUT_EN) |= (0x1<< pin_settings.pin);
	}

	GPIO_REG(GPIO_PULLUP_EN) ^= (-(pin_settings.pull & 0x01) ^ GPIO_REG(GPIO_PULLUP_EN)) & (1UL << pin_settings.pin);
	GPIO_REG(GPIO_DRIVE) ^= (-(pin_settings.drive & 0x01) ^ GPIO_REG(GPIO_DRIVE)) & (1UL << pin_settings.pin);
	GPIO_REG(GPIO_IOF_EN) ^= (-(pin_settings.mode & 0x01) ^ GPIO_REG(GPIO_IOF_EN)) & (1UL << pin_settings.pin);
	GPIO_REG(GPIO_IOF_SEL) ^= (-(pin_settings.select_alt & 0x01) ^ GPIO_REG(GPIO_IOF_SEL)) & (1UL << pin_settings.pin);
	GPIO_REG(GPIO_OUTPUT_XOR) ^= (-(pin_settings.invert & 0x01) ^ GPIO_REG(GPIO_OUTPUT_XOR)) & (1UL << pin_settings.pin);
}

uint8_t per_gpio_read(gpio_pin_t pin_settings)
{
	return (uint8_t)((GPIO_REG(GPIO_INPUT_VAL) & (0x1 << pin_settings.pin)) >> (0x1 << pin_settings.pin));
}

void per_gpio_write(gpio_pin_t pin_settings, uint8_t value)
{
	GPIO_REG(GPIO_OUTPUT_VAL) ^= (-(value & 0x01) ^ GPIO_REG(GPIO_OUTPUT_VAL)) & (1UL << pin_settings.pin);
}

void per_gpio_toggle(gpio_pin_t pin_settings)
{
	GPIO_REG(GPIO_OUTPUT_VAL) ^= (0x1 << pin_settings.pin);
}


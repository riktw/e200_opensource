TARGET = gpio_test
CFLAGS += -O2 -DUSE_PLIC -DUSE_M_TIME

BSP_BASE = ../../bsp

C_SRCS += demo_gpio.c
C_SRCS += $(BSP_BASE)/drivers/plic/plic_driver.c

INCLUDES += -I$(BSP_BASE)/drivers/periph/
C_SRCS += $(BSP_BASE)/drivers/periph/per_gpio.c
C_SRCS += $(BSP_BASE)/drivers/periph/per_pwm.c

include $(BSP_BASE)/env/common.mk

/* mbed Microcontroller Library
 * Copyright(C) TOSHIBA ELECTRONIC DEVICES & STORAGE CORPORATION 2022
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef MBED_PERIPHERALNAMES_H
#define MBED_PERIPHERALNAMES_H

#include "PinNames.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    SERIAL_0 = 0,
    SERIAL_1,
    SERIAL_2,
    SERIAL_3,
    SERIAL_4,
    SERIAL_5,
    INVALID_SERIAL = (int)NC
} UARTName;

typedef enum {
    DAC_0 = 0,
    DAC_1,
    INVALID_DAC = (int)NC
} DACName;

typedef enum {
    PWM_0 = 0,
    PWM_1,
    PWM_2,
    PWM_3,
    PWM_4,
    PWM_5,
    PWM_6,
    PWM_7,
    PWM_8,
    PWM_9,
    PWM_10,
    PWM_11,
    PWM_12,
    INVALID_PWM = (int)NC
} PWMName;

typedef enum {
    ADC_A0  = 0,
    ADC_A1,
    ADC_A2,
    ADC_A3,
    ADC_A4,
    ADC_A5,
    ADC_A6,
    ADC_A7,
    ADC_A9  = 9,
    ADC_A14 = 14,
    ADC_A17 = 17,
    ADC_A18,
    ADC_A19,
    ADC_A20,
    ADC_A21,
    ADC_A22,
    ADC_A23,
    INVALID_ADC = (int)NC
} ADCName;

typedef enum {
    I2C_0 = 0,
    I2C_1,
    I2C_2,
    I2C_3,
    INVALID_I2C = (int)NC
} I2CName;

typedef enum {
    SPI_0 = 0,
    SPI_1,
    INVALID_SPI = (int)NC
} SPIName;

typedef enum {
    GPIO_IRQ_0 = 0,
    GPIO_IRQ_1,
    GPIO_IRQ_2,
    GPIO_IRQ_3,
    GPIO_IRQ_4,
    GPIO_IRQ_5,
    GPIO_IRQ_6,
    GPIO_IRQ_7,
    GPIO_IRQ_8,
    GPIO_IRQ_9,
    GPIO_IRQ_A,
    GPIO_IRQ_B,
    GPIO_IRQ_C,
    GPIO_IRQ_D,
    GPIO_IRQ_E,
    GPIO_IRQ_F,
    INVALID_GPIO_IRQ = (int)NC
} GPIO_IRQName;

// DAP UART
#if defined(MBED_CONF_TARGET_STDIO_UART_TX)
#define STDIO_UART_TX MBED_CONF_TARGET_STDIO_UART_TX
#else
#define STDIO_UART_TX CONSOLE_TX
#endif
#if defined(MBED_CONF_TARGET_STDIO_UART_RX)
#define STDIO_UART_RX MBED_CONF_TARGET_STDIO_UART_RX
#else
#define STDIO_UART_RX CONSOLE_RX
#endif

#define SERIAL_TX         PV1
#define SERIAL_RX         PV0

#define STDIO_UART        SERIAL_2

// TxD RxD
#define MBED_UART0        PE3, PE2
#define MBED_UART1        PV5, PV4
#define MBED_UART2        PV1, PV0
#define MBED_UART3        PJ1, PJ0
#define MBED_UART4        PJ4, PJ5
#define MBED_UART5        PJ6, PJ7
#define MBED_UARTUSB      CONSOLE_TX, CONSOLE_RX

// SDA SCK
#define MBED_I2C0         PF2, PF3
#define MBED_I2C1         PV5, PV4
#define MBED_I2C2         PJ6, PJ7
#define MBED_I2C3         PJ3, PJ2

// MOSI, MISO, SCLK SS
#define MBED_SPI0         PA3, PA2, PA1, PA0
#define MBED_SPI1         PA4, PA5, PA6, PA7

#define MBED_ANALOGIN0    A0
#define MBED_ANALOGIN1    A1
#define MBED_ANALOGIN2    A2
#define MBED_ANALOGIN3    A3
#define MBED_ANALOGIN4    A4
#define MBED_ANALOGIN5    A5

#define MBED_PWMOUT0      PW1
#define MBED_PWMOUT1      PW2
#define MBED_PWMOUT2      PT3
#define MBED_PWMOUT3      PD2
#define MBED_PWMOUT4      PD4
#define MBED_PWMOUT5      PE1
#define MBED_PWMOUT6      PE6
#define MBED_PWMOUT7      PL4
#define MBED_PWMOUT8      PL6
#define MBED_PWMOUT9      PC4
#define MBED_PWMOUT10     PW6
#define MBED_PWMOUT11     PU0
#define MBED_PWMOUT12     PU6

#ifdef __cplusplus
}
#endif
#endif

# Copyright (c) 2020 ARM Limited. All rights reserved.
# SPDX-License-Identifier: Apache-2.0

add_subdirectory(TARGET_STM32G030x8 EXCLUDE_FROM_ALL)
add_subdirectory(TARGET_STM32G031x8 EXCLUDE_FROM_ALL)
add_subdirectory(TARGET_STM32G041x8 EXCLUDE_FROM_ALL)
add_subdirectory(TARGET_STM32G050x8 EXCLUDE_FROM_ALL)
add_subdirectory(TARGET_STM32G051x8 EXCLUDE_FROM_ALL)
add_subdirectory(TARGET_STM32G061x8 EXCLUDE_FROM_ALL)
add_subdirectory(TARGET_STM32G070xB EXCLUDE_FROM_ALL)
add_subdirectory(TARGET_STM32G071xB EXCLUDE_FROM_ALL)
add_subdirectory(TARGET_STM32G081xB EXCLUDE_FROM_ALL)
add_subdirectory(TARGET_STM32G0B0xE EXCLUDE_FROM_ALL)
add_subdirectory(TARGET_STM32G0B1xE EXCLUDE_FROM_ALL)

add_subdirectory(TARGET_STM32G0C1xE EXCLUDE_FROM_ALL)

add_subdirectory(STM32Cube_FW EXCLUDE_FROM_ALL)

add_library(mbed-stm32g0 INTERFACE)

target_include_directories(mbed-stm32g0
    INTERFACE
        .
)

target_sources(mbed-stm32g0
    INTERFACE
        analogin_device.c
        analogout_device.c
        flash_api.c
        gpio_irq_device.c
        i2c_device.c
        pwmout_device.c
        serial_device.c
        spi_api.c
)

target_link_libraries(mbed-stm32g0 INTERFACE mbed-stm mbed-stm32g0cube-fw)

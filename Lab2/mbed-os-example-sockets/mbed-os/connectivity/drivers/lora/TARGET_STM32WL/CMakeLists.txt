# Copyright (c) 2020 ARM Limited. All rights reserved.
# SPDX-License-Identifier: Apache-2.0

target_include_directories(mbed-lorawan
    INTERFACE
        .
)

target_sources(mbed-lorawan
    INTERFACE
        STM32WL_LoRaRadio.cpp
        STM32WL_radio_driver.cpp
)

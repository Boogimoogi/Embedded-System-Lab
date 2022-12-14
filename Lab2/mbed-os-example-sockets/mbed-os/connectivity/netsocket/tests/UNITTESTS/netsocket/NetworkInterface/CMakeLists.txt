# Copyright (c) 2021 ARM Limited. All rights reserved.
# SPDX-License-Identifier: Apache-2.0

include(GoogleTest)

set(TEST_NAME netsocket-network-interface-unittest)

add_executable(${TEST_NAME})

target_compile_definitions(${TEST_NAME}
    PRIVATE
        MBED_CONF_PLATFORM_CALLBACK_COMPARABLE
        MBED_CONF_NSAPI_DNS_ADDRESSES_LIMIT=10

)

target_sources(${TEST_NAME}
    PRIVATE
        ${mbed-os_SOURCE_DIR}/connectivity/netsocket/source/NetworkInterface.cpp
        ${mbed-os_SOURCE_DIR}/connectivity/libraries/nanostack-libservice/source/libList/ns_list.c
        test_NetworkInterface.cpp
)

target_link_libraries(${TEST_NAME}
    PRIVATE
        mbed-headers-nanostack-libservice
        mbed-headers-netsocket
        mbed-stubs
        mbed-stubs-headers
        mbed-stubs-netsocket
        gmock_main
)

gtest_discover_tests(${TEST_NAME} PROPERTIES LABELS "netsocket")

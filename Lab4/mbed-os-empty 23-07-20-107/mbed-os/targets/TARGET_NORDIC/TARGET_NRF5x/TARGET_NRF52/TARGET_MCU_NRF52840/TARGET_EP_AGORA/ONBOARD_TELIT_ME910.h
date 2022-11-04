/* mbed Microcontroller Library
 * Copyright (c) 2006-2019 ARM Limited
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

#ifndef ONBOARD_TELIT_ME910_
#define ONBOARD_TELIT_ME910_

#include "TELIT_ME910.h"

namespace mbed {

class ONBOARD_TELIT_ME910 : public TELIT_ME910 {
public:
    ONBOARD_TELIT_ME910(FileHandle *fh);

    virtual nsapi_error_t init();
    virtual nsapi_error_t hard_power_on();
    virtual nsapi_error_t hard_power_off();
    virtual nsapi_error_t soft_power_on();
    virtual nsapi_error_t soft_power_off();

private:
    void press_power_button(int time_ms);

    void onboard_modem_init();

    void onboard_modem_deinit();

    void onboard_modem_power_up();

    void onboard_modem_power_down();
};

} // namespace mbed

#endif // ONBOARD_TELIT_ME910_

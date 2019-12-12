/* ATMega238pb sound processing experiments - data sampling header-file
Copyright 2019 Alex Isabelle Shuping

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
 */
#ifndef SAMPLING_H
#define SAMPLING_H

#include "common.h"

// CAUTION! IF YOU CHANGE THESE VALUES, YOU MUST ALSO UPDATE THE PRECOMPUTED
// COEFFICIENTS IN goertzel.h - THESE ARE NOT COMPUTED AUTOMATICALLY!
#define ADC_VAL_BUF_SIZE 512

#define F_SAMPLING 8000 // This is not used to determine the timer frequency -
                        // Make sure that the values in setup_sampling_tcounter
                        // are appropriate to create this frequency.

extern volatile uint16_t* g_adc_val_buf;
extern volatile uint16_t g_adc_val_buf_cur;
extern volatile uint8_t g_adc_new_data;

void setup_sampling();
void setup_sampling_tcounter();
void setup_sampling_adc();
void start_sampling();
void stop_sampling();
#endif
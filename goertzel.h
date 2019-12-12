/* ATMega238pb sound processing experiments - Goertzel algorithm and related operations - header-file
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
#pragma once

#include "sampling.h"

extern volatile float target_freq_magnitude_squared;
extern volatile uint8_t goertzel_ready;

void goertzel_per_sample();
void goertzel_end_of_block();

/* Thanks to:
 * https://www.embedded.com/the-goertzel-algorithm/
 * for details on how to implement the Goertzel algorithm.
 */

#define F_TARGET 525
// Calculations are done as if F_TARGET was doubled (i.e. 1050)
// need to do more research to figure out why this is necessary

// k = (int)(0.5*(N*f_target)/(f_sampling))
//#define GOERTZEL_K (uint8_t)(0.5*((float)ADC_VAL_BUF_SIZE*(float)F_TARGET)/((float)F_SAMPLING))
#define GOERTZEL_K (uint8_t)34

// THESE VALUES MUST BE MANUALLY CALCULATED
// w0 = (2*pi/N)*k
//#define W0 (float)(0.006136*(float)GOERTZEL_K)
#define W0 (float)0.417243

// cosw0 = cos(w0)
// sinw0 = sin(w0)
#define COSW0 (float)0.914210
#define SINW0 (float)0.405241

// Goertzel coefficient = 2*cos(w0)
//#define GOERTZEL_COEFF 2*COSW0
#define GOERTZEL_COEFF (float)1.82842

#define GOERTZEL_SCALING_COEFF (float)5e6
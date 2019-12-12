/* ATMega238pb sound processing experiments - Goertzel algorithm and related operations
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

#include "goertzel.h"
#include "sampling.h"

volatile float target_freq_magnitude_squared;
volatile uint8_t goertzel_ready;

volatile float q0;
volatile float q1;
volatile float q2;

void goertzel_per_sample(){
	if(g_adc_val_buf_cur == 0){
		q1 = 0.0;
		q2 = 0.0;
	}

	q0 = GOERTZEL_COEFF*q1 - q2 + g_adc_val_buf[g_adc_val_buf_cur];
	q2 = q1;
	q1 = q0;
}

void goertzel_end_of_block(){
	target_freq_magnitude_squared = (q1*q1 + q2*q2 - q1*q2*GOERTZEL_COEFF)/GOERTZEL_SCALING_COEFF;
	goertzel_ready = 1;
}
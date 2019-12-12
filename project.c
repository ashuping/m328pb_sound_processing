/* ATMega238pb sound processing experiments - main file
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

#ifndef F_CPU
	#define F_CPU 8000000UL
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>

#include "common.h"
#include "sampling.h"
#include "goertzel.h"
#include "usart.h"

int main(void){
	setup_usart();
	println("Initializing...");
	setup_sampling();
	start_sampling();
	goertzel_ready = 0;
	sei();
	println("Beginning main loop...");

	uint8_t values[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	uint8_t values_index = 0;
	
	while(1){
		if(goertzel_ready){
			values[values_index] = (uint8_t)target_freq_magnitude_squared;
			values_index = values_index == 15 ? 0 : values_index+1;
			
			uint16_t sum = 0;
			for(uint8_t i = 0; i < 16; ++i){
				sum += values[i];
			}

			uint8_t sum_capped = sum > 255 ? 255 : (uint8_t)sum;

			char str[50];
			sprintf(str, "%i", sum_capped);
			cli();
			println(str);
			sei();
			goertzel_ready = 0;
		}
	}
	return 0;
}
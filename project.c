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
#include "usart.h"

int main(void){
	setup_usart();
	println("Initializing...");
	setup_sampling();
	start_sampling();
	sei();
	println("Beginning main loop...");
	
	while(1){
		if(g_adc_new_data){
			uint8_t words_ready = g_adc_new_data;
			g_adc_new_data = 0;
			char str[50]; // = 40 (text) + 3 (8-bit uint) + 4 (10-bit uint) + 2 (for good luck)
			sprintf(str, "%u words ready from ADC. Most recent is %x", words_ready, g_adc_val_buf[g_adc_val_buf_cur]);
			println(str);
		}
		_delay_ms(100);
	}
	return 0;
}
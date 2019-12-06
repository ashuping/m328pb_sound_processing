/* ATMega238pb sound processing experiments - USART
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
#include <avr/io.h>

#include "common.h"
#include "usart.h"

void setup_usart(){
	DDRD |= (1 << DDD1);

	UBRR0H = 0;
	UBRR0L = 12;

	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
}

void _transmit_char(const char to_transmit){
	while(!(UCSR0A & (1 << UDRE0)));
	UDR0 = to_transmit;
}

void transmit(const char* to_transmit){
	for(uint8_t i = 0; to_transmit[i] != 0; ++i){
		_transmit_char(to_transmit[i]);
	}
}

void println(const char* to_transmit){
	transmit(to_transmit);
	transmit("\n\r");
}
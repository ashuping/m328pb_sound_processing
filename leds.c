/* ATMega238pb sound processing experiments - LED PWM setup
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
#include "leds.h"

#include <avr/io.h>

void setup_tone(){

    DDRD |= (1 << DDD0);

    ICR3 = 12;
    OCR3A = 6;

    TCCR3A = (1 << COM3A1) | (1 << WGM31);
    TCCR3B = (1 << WGM33) | (1 << WGM32);
}

void start_tone(){
    TCCR3B |= (1 << CS32) | (1 << CS30);
}

void stop_tone(){
    TCCR3B &= ~((1 << CS32) | (1 << CS30));
}

void setup_led_timer(){
    TCCR0A = (1 << COM0A1) | (1 << WGM00) | (1 << WGM01); // Fast PWM, set OCR0A for PWM output
    DDRD |= (1 << DDD6);
}

void start_pwm(){
    TCCR0B |= (1 << CS02) | (1 << CS00); // Run timer at 1/1024th-clock
}

void stop_pwm(){
    TCCR0B &= ~((1 << CS02) | (1 << CS00)); // Stop timer
}
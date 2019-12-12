/* ATMega238pb sound processing experiments - data sampling
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
#include <avr/interrupt.h>

#include <stdlib.h>

#include "common.h"
#include "sampling.h"
#include "goertzel.h"
#include "usart.h"

volatile uint16_t* g_adc_val_buf;
volatile uint16_t g_adc_val_buf_cur;
volatile uint8_t g_adc_new_data;

void setup_sampling(){
    g_adc_val_buf = malloc(ADC_VAL_BUF_SIZE*sizeof(uint16_t));
    g_adc_val_buf_cur = 0;
    g_adc_new_data = 0;
    setup_sampling_tcounter();
    setup_sampling_adc();
}

void setup_sampling_tcounter(){
    // CAUTION! IF YOU CHANGE THE SAMPLING RATE, YOU MUST ALSO UPDATE THE
    // PRECOMPUTED COEFFICIENTS IN goertzel.h - THESE ARE NOT COMPUTED
    // AUTOMATICALLY!
    TCCR1B |= (1 << WGM12); // CTC-mode, use OCR1A
    OCR1A = (uint16_t)999; // Sample at 8kHz
    OCR1B = (uint16_t)999; // OCR1B is used for ADC auto-sampling
}

void setup_sampling_adc(){
    ADCSRA = (1 << ADIE) | (1 << ADPS2) | (1 << ADPS2); // Enable interrupt on sample completion, prescale to ~= 125kHz
    ADCSRB = (1 << ADTS2) | (1 << ADTS0); // Start capture at OCR1B match
    ADMUX = (1 << REFS0); // Reference AVcc
}

void start_sampling(){
    ADCSRA |= (1 << ADEN) | (1 << ADATE); // Enable ADC and auto-conversion
    TCCR1B |= (1 << CS10); // Start counting with no prescaling
}

void stop_sampling(){
    ADCSRA &= ~((1 << ADEN) | (1 << ADATE)); // Disable ADC, disable auto-conversion
    TCCR1B &= ~(7 << CS10); // Disable counter
}

ISR(ADC_vect){
    g_adc_val_buf[(g_adc_val_buf_cur+1) % ADC_VAL_BUF_SIZE] = ADC;
    g_adc_val_buf_cur = (g_adc_val_buf_cur == ADC_VAL_BUF_SIZE) ? 0 : g_adc_val_buf_cur + 1;
    g_adc_new_data = (g_adc_new_data == 255) ? 255 : g_adc_new_data + 1;
    goertzel_per_sample();
    if(g_adc_val_buf_cur == ADC_VAL_BUF_SIZE){
        goertzel_end_of_block();
    }
    TIFR1 |= (1 << OCF1B);
}
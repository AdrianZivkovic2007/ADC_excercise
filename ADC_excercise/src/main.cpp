/*
  Name: Adrian Zivkovic
  Datum: 25.05.2025
  Projekt: ADC_excercise
*/

#include <Arduino.h>

#define ADC_CHANNEL 0

volatile int poti_value = 0;

void setup() {
  Serial.begin(115200);

  // Enable ADC, enable ADC interrupt, set prescaler to 128 (16MHz / 128 = 125kHz)
  ADCSRA |= (1 << ADEN) | (1 << ADIE) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

  // Select ADC channel and set internal 5V reference (AVcc)
  ADMUX = (ADMUX & 0b11110000) | ADC_CHANNEL;
  ADMUX |= (1 << REFS0);

  sei();                  // Enable global interrupts
  ADCSRA |= (1 << ADSC);  // Start first ADC conversion
}

void loop() {
  float voltage = (poti_value * 5.0) / 1023;

  Serial.print("Potentiometer analog value = ");
  Serial.print(voltage, 2);
  Serial.println(" V");

  delay(500); // Print value every 500ms
}

// This ISR is called when an ADC conversion is complete
ISR(ADC_vect) {
  poti_value = ADC;        // Read ADC result
  ADCSRA |= (1 << ADSC);   // Start next ADC conversion
}


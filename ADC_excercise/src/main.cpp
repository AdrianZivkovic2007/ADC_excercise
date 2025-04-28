/*
  Name: Adrian Zivkovic
  Datum: 25.05.2025
  Projekt: ADC_excercise
*/

#include <Arduino.h>

const int potPin = A0;
const unsigned long interval = 500;
unsigned long previousMillis = 0;

void setup() {
Serial.begin(115200);
ADCSRA |= (1 << ADPS2) | (1 << ADPS1);
ADMUX = (1 << MUX0);
}

void loop() {
unsigned long currentMillis = millis();

if (currentMillis - previousMillis >= interval) {
previousMillis = currentMillis;
ADCSRA |= (1 << ADSC);
while (ADCSRA & (1 << ADSC));

int adcValue = ADC;
float voltage = adcValue * (5.0 / 1023.0);
Serial.print("Potentiometer analog value = ");
Serial.print(voltage, 2);
Serial.println(" V");
}
}

 ADC_excercise

#Wichtige Register:
ADMUX: Wählt den ADC-Eingang und die Referenzspannung. Beispiel: ADMUX = 0b00000000 wählt A0.

ADCSRA: Steuert den ADC (aktiviert ihn, setzt den Prescaler, ermöglicht Interrupts). Wichtigste Bits:

ADEN: Aktiviert den ADC.

ADPS[2:0]: Bestimmt den Prescaler (z. B. 64).

ADIE: Aktiviert Interrupts.

ADSC: Startet die Konvertierung.

Prescaler:
Der Prescaler steuert die ADC-Taktfrequenz. Bei einem 16 MHz Takt ist Prescaler = 64 eine gute Wahl, um eine Frequenz von ca. 250 kHz zu erhalten.

Multiplexer:
ADMUX stellt den Eingangs-Pin ein, z. B. A0 als Eingang.

Start der Konvertierung:
Die Konvertierung wird durch Setzen des ADSC-Bits im ADCSRA-Register gestartet.

Interrupts:
Aktivierung von Interrupts mit ADIE im ADCSRA. Sobald die Konvertierung abgeschlossen ist, wird der Interrupt ausgelöst und der Wert aus ADC ausgelesen.

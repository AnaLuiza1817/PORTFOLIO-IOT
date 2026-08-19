// C++ code
#include <button.h>



int buttonPin = 7;
int ledPin = 10;
bool estadoLed = false;

void setup() {
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT);
}

void loop() {
    if (digitalRead(buttonPin) == HIGH) {
    estadoLed = !estadoLed;
    digitalWrite(ledPin, estadoLed);
    delay(500);
    }
}

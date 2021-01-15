//
// Created by samuel on 15-01-21.
//

#include "test_utils.h"

bool assertHigh(int pin) {
    if (digitalRead(pin)) return true;

    Serial.print("   assertHigh error: pin ");
    Serial.print(pin);
    Serial.println(" is not high");

    digitalWrite(LED_BUILTIN, HIGH);
    return false;
}

bool assertHigh(int pin, char *message) {
    if (assertHigh(pin)) return true;

    Serial.print("   -> ");
    Serial.println(message);
    return false;
}

bool assertLow(int pin) {
    if (!digitalRead(pin)) return true;

    Serial.print("   assertLow error: pin ");
    Serial.print(pin);
    Serial.println(" is not low");

    digitalWrite(LED_BUILTIN, HIGH);
    return false;
}

bool assertLow(int pin, char *message) {
    if (assertLow(pin)) return true;

    Serial.print("   -> ");
    Serial.println(message);
    return false;
}

void pulse(int pin) {
    step();
    digitalWrite(pin, HIGH);
    step();
    digitalWrite(pin, LOW);
    step();
}

void pulse_invert(int pin) {
    step();
    digitalWrite(pin, LOW);
    step();
    digitalWrite(pin, HIGH);
    step();
}
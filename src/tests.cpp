//
// Created by samuel on 15-01-21.
//

#include "tests.h"

// Custom function used by these tests
void setAllParallelInputs(int value) {
    digitalWrite(PIN_H, value);
    digitalWrite(PIN_G, value);
    digitalWrite(PIN_F, value);
    digitalWrite(PIN_E, value);
    digitalWrite(PIN_D, value);
    digitalWrite(PIN_C, value);
    digitalWrite(PIN_B, value);
    digitalWrite(PIN_A, value);
}

// Mandatory function which runs once before running all tests. Basically everything you would put in setup().
void beforeAll() {
    pinMode(PIN_SER, OUTPUT);
    pinMode(PIN_LD, OUTPUT);
    pinMode(PIN_CLK, OUTPUT);
    pinMode(PIN_CLK_INH, OUTPUT);
    pinMode(PIN_QH, INPUT);
    pinMode(PIN_QH_INV, INPUT);
    pinMode(PIN_A, OUTPUT);
    pinMode(PIN_B, OUTPUT);
    pinMode(PIN_C, OUTPUT);
    pinMode(PIN_D, OUTPUT);
    pinMode(PIN_E, OUTPUT);
    pinMode(PIN_F, OUTPUT);
    pinMode(PIN_G, OUTPUT);
    pinMode(PIN_H, OUTPUT);
}

// Mandatory function which runs before executing a test. Basically resets everything for the new test.
void beforeEach() {
    digitalWrite(PIN_LD, HIGH);
    digitalWrite(PIN_SER, LOW);
    digitalWrite(PIN_CLK, HIGH);
    digitalWrite(PIN_CLK_INH, LOW);
    setAllParallelInputs(LOW);

    // Load low values
    pulse_invert(PIN_LD);
}


void test_low_inputs_gives_low_output() {
    Serial.println("Running test: test_low_inputs_gives_low_output");

    // When
    pulse(PIN_CLK);
    // Then
    assertLow(PIN_QH, (char *) "Parallel input H");

    pulse(PIN_CLK);
    assertLow(PIN_QH, (char *) "Parallel input G");

    pulse(PIN_CLK);
    assertLow(PIN_QH, (char *) "Parallel input F");

    pulse(PIN_CLK);
    assertLow(PIN_QH, (char *) "Parallel input E");

    pulse(PIN_CLK);
    assertLow(PIN_QH, (char *) "Parallel input D");

    pulse(PIN_CLK);
    assertLow(PIN_QH, (char *) "Parallel input C");

    pulse(PIN_CLK);
    assertLow(PIN_QH, (char *) "Parallel input B");

    pulse(PIN_CLK);
    assertLow(PIN_QH, (char *) "Parallel input A");

    pulse(PIN_CLK);
    assertLow(PIN_QH, (char *) "First bit from SER input");
}

void test_high_inputs_gives_low_output() {
    Serial.println("Running test: test_high_inputs_gives_low_output");

    // Given
    setAllParallelInputs(HIGH);
    pulse_invert(PIN_LD);

    setAllParallelInputs(LOW);

    // When
    pulse(PIN_CLK);
    // Then
    assertHigh(PIN_QH, (char *) "Parallel input H");

    pulse(PIN_CLK);
    assertHigh(PIN_QH, (char *) "Parallel input G");

    pulse(PIN_CLK);
    assertHigh(PIN_QH, (char *) "Parallel input F");

    pulse(PIN_CLK);
    assertHigh(PIN_QH, (char *) "Parallel input E");

    pulse(PIN_CLK);
    assertHigh(PIN_QH, (char *) "Parallel input D");

    pulse(PIN_CLK);
    assertHigh(PIN_QH, (char *) "Parallel input C");

    pulse(PIN_CLK);
    assertHigh(PIN_QH, (char *) "Parallel input B");

    pulse(PIN_CLK);
    assertHigh(PIN_QH, (char *) "Parallel input A");

    pulse(PIN_CLK);
    assertLow(PIN_QH, (char *) "First bit from SER input");
}

void test_high_low_inputs_gives_high_low_output() {
    Serial.println("Running test: test_high_low_inputs_gives_high_low_output");

    // Given
    digitalWrite(PIN_H, LOW);
    digitalWrite(PIN_G, LOW);
    digitalWrite(PIN_F, HIGH);
    digitalWrite(PIN_E, HIGH);
    digitalWrite(PIN_D, LOW);
    digitalWrite(PIN_C, HIGH);
    digitalWrite(PIN_B, LOW);
    digitalWrite(PIN_A, HIGH);
    pulse_invert(PIN_LD);

    setAllParallelInputs(LOW);

    // When
    pulse(PIN_CLK);

    // Then
    assertLow(PIN_QH, (char *) "Parallel input H");

    pulse(PIN_CLK);
    assertLow(PIN_QH, (char *) "Parallel input G");

    pulse(PIN_CLK);
    assertHigh(PIN_QH, (char *) "Parallel input F");

    pulse(PIN_CLK);
    assertHigh(PIN_QH, (char *) "Parallel input E");

    pulse(PIN_CLK);
    assertLow(PIN_QH, (char *) "Parallel input D");

    pulse(PIN_CLK);
    assertHigh(PIN_QH, (char *) "Parallel input C");

    pulse(PIN_CLK);
    assertLow(PIN_QH, (char *) "Parallel input B");

    pulse(PIN_CLK);
    assertHigh(PIN_QH, (char *) "Parallel input A");

    pulse(PIN_CLK);
    assertLow(PIN_QH, (char *) "First bit from SER input");
}

void test_serial_input_gets_through() {
    Serial.println("Running test: test_serial_input_gets_through");

    // When: loading serial data into the component
    digitalWrite(PIN_SER, LOW);
    pulse(PIN_CLK);
    digitalWrite(PIN_SER, HIGH);
    pulse(PIN_CLK);
    digitalWrite(PIN_SER, HIGH);
    pulse(PIN_CLK);
    digitalWrite(PIN_SER, LOW);
    pulse(PIN_CLK);
    digitalWrite(PIN_SER, HIGH);
    pulse(PIN_CLK);
    digitalWrite(PIN_SER, LOW);
    pulse(PIN_CLK);
    pulse(PIN_CLK);

    // Then
    pulse(PIN_CLK);
    assertLow(PIN_QH, (char *) "Serial input #1");

    pulse(PIN_CLK);
    assertHigh(PIN_QH, (char *) "Serial input #2");

    pulse(PIN_CLK);
    assertHigh(PIN_QH, (char *) "Serial input #3");

    pulse(PIN_CLK);
    assertLow(PIN_QH, (char *) "Serial input #4");

    pulse(PIN_CLK);
    assertHigh(PIN_QH, (char *) "Serial input #5");

    pulse(PIN_CLK);
    assertLow(PIN_QH, (char *) "Serial input #6");

    pulse(PIN_CLK);
    assertLow(PIN_QH, (char *) "Serial input #7");

    pulse(PIN_CLK);
    assertLow(PIN_QH, (char *) "Serial input #8");
}
#include <Arduino.h>
#include "config.h"
#include "tests.h"

/*
 * Add tests to be executed here:
 */
const int amount_of_tests = 4;
void_pointer tests[amount_of_tests] = {
        &test_low_inputs_gives_low_output,
        &test_high_inputs_gives_low_output,
        &test_high_low_inputs_gives_high_low_output,
        &test_serial_input_gets_through,
};

/* ************** */


void setup() {
    Serial.begin(BAUD_RATE);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    Serial.print("Running ");
    Serial.print(amount_of_tests);
    Serial.println(" tests...\n");
    digitalWrite(LED_BUILTIN, LOW);

    beforeAll();

    for (auto &test : tests) {
        beforeEach();
        test();

        Serial.print("\n\n");
    }

    Serial.println("--------------");
    Serial.print("Done running ");
    Serial.print(amount_of_tests);
    Serial.println(" tests.\n\n");

    delay(5000);
    Serial.println("Restart in 10 seconds...");
    delay(10000);
    Serial.println("Restarting tests...\n\n\n");
}

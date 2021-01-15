//
// Created by samuel on 15-01-21.
//

#ifndef TEST_74HC165N_TESTS_H
#define TEST_74HC165N_TESTS_H

#include <Arduino.h>
#include "config.h"
#include "test_utils.h"

// MANDATORY
void beforeAll();

void beforeEach();

// OPTIONAL
void test_low_inputs_gives_low_output();

void test_high_inputs_gives_low_output();

void test_high_low_inputs_gives_high_low_output();

void test_serial_input_gets_through();

#endif //TEST_74HC165N_TESTS_H

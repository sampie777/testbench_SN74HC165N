//
// Created by samuel on 15-01-21.
//

#ifndef TEST_74HC165N_TEST_UTILS_H
#define TEST_74HC165N_TEST_UTILS_H

#include <Arduino.h>
#include "config.h"

#define step() delay(STEP_TIME)

typedef void (*void_pointer)();

bool assertHigh(int pin);

bool assertHigh(int pin, char *message);

bool assertLow(int pin);

bool assertLow(int pin, char *message);

void pulse(int pin);

void pulse_invert(int pin);

#endif //TEST_74HC165N_TEST_UTILS_H

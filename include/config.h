//
// Created by samuel on 15-01-21.
//

#ifndef TEST_74HC165N_CONFIG_H
#define TEST_74HC165N_CONFIG_H

/*
 * (Arduino) Pins (to connect the to be tested component to)
 */
#define PINS_OFFSET 21
#define PIN_LD (PINS_OFFSET + 1)
#define PIN_CLK (PINS_OFFSET + 2)
#define PIN_E (PINS_OFFSET + 3)
#define PIN_F (PINS_OFFSET + 4)
#define PIN_G (PINS_OFFSET + 5)
#define PIN_H (PINS_OFFSET + 6)
#define PIN_QH_INV (PINS_OFFSET + 7)
//#define PIN_GND (PINS_OFFSET + 8)
//#define PIN_VCC (PINS_OFFSET + 9)
#define PIN_CLK_INH (PINS_OFFSET + 10)
#define PIN_D (PINS_OFFSET + 11)
#define PIN_C (PINS_OFFSET + 12)
#define PIN_B (PINS_OFFSET + 13)
#define PIN_A (PINS_OFFSET + 14)
#define PIN_SER (PINS_OFFSET + 15)
#define PIN_QH (PINS_OFFSET + 16)

/*
 * Application
 */
// Time in milliseconds for a simulated step
#define STEP_TIME 1

// Baud rate for serial communications
#define BAUD_RATE 115200

#endif //TEST_74HC165N_CONFIG_H

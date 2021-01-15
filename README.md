# Testbench for SN74HC165N

___

8-bit parallel-load shift register.

Data sheet: [https://www.ti.com/lit/ds/symlink/sn74hc165.pdf?ts=1610693702508](https://www.ti.com/lit/ds/symlink/sn74hc165.pdf?ts=1610693702508).

Currently implemented tests covers the following:

- Loaded input values shifts out correctly
- Loaded serial values shifts out correctly

## Setup

1. Connect the component to the configured pins of the **Arduino Mega** as in [config.h](include/config.h). You may adjust these pin settings to your likings. (Note: connect VCC and GND of the component to VCC and GND of the Arduino and not to the digital pins).
1. Connect the Arduino Mega to your computer.
1. Open up a serial monitor with the specified baud rate (default: 115200, see [config.h](include/config.h)).

If you don't have a PC nearby, you could also use just the onboard LED:
If the onboard LED turns on for most of the time, tests have failed. If it is constantly off, all tests have passed.

The serial monitor will display information about the tests run: the test's name and any failures during the test.

## Adding/modifying tests

The tests to be run are found in [tests.cpp](src/tests.cpp). Here you can add more tests, modify tests, and also configure the mandatory functions: `beforeAll()` and `beforeEach()`.

### Adding new tests

When adding new tests, make sure the functions are made available in the [test.h](include/tests.h) header file. Also, add these function names to the `tests[]` array in [main.cpp](src/main.cpp). (Don't forget to update `amount_of_tests`).

### Assertions

The functions `assertHigh(pin[, message])` and `assertLow(pin[, message])` can be used to handle assertions for pin input readings. The optional `message` argument will display more information when the assertion fails. This can be useful debugging which assertion failed. Both functions return `true` if the assertion was successful, otherwise false.

___

> Note: This project is a PlatformIO project, created using it's CLion plugin, for the Arduino Mega. Hence the folder structure.
/**
 * Copyright (c) 2022 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

// This template is based on the "access_point" exemple from https://github.com/raspberrypi/pico-examples/tree/master/pico_w/wifi/access_point

#include "controlVariables.h"
#include "server.h"

// Declare ControlVariables
volatile bool blinking = false;
volatile uint32_t blinkSpeed = 100;
volatile MotorMode motorMode = MotorMode::Stopped;
volatile uint32_t motorSpeed = 1200;

// Init Motor constants
const uint stepCount = 8;
int steps[8][4] = {{1, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 1}, {0, 0, 0, 1}, {1, 0, 0, 1}};
const uint MOTOR_PIN_1 = 18;
const uint MOTOR_PIN_2 = 19;
const uint MOTOR_PIN_3 = 20;
const uint MOTOR_PIN_4 = 21;

int nextStep(int currentStep, bool backward) {
    if (backward) {
        if (currentStep <= 0) {
            return stepCount-1;
        } else {
            return currentStep-1;
        }
        return currentStep-1;
    } else {
        return (currentStep+1)%stepCount;
    }
}

int main() {
    // Init
    stdio_init_all();
    if (cyw43_arch_init()) {
        DEBUG_printf("failed to initialise\n");
        return 1;
    }
    
    // You can setup your access point name & password here
    int serverInitResult = serverInit("equatorial mount", "polar-star");
    if(serverInitResult != 0) {
        return serverInitResult;
    }

    // New way to light the onboard led
    cyw43_gpio_set(&cyw43_state, 0, true);


    // Init Motor GPIO
    gpio_init(MOTOR_PIN_1);
    gpio_init(MOTOR_PIN_2);
    gpio_init(MOTOR_PIN_3);
    gpio_init(MOTOR_PIN_4);
    gpio_set_dir(MOTOR_PIN_1, GPIO_OUT);
    gpio_set_dir(MOTOR_PIN_2, GPIO_OUT);
    gpio_set_dir(MOTOR_PIN_3, GPIO_OUT);
    gpio_set_dir(MOTOR_PIN_4, GPIO_OUT);

    int currentStep = 0;
    while(!state->complete) {
        // Do your usual pico stuff here
        if (motorMode != MotorMode::Stopped) {
            gpio_put(MOTOR_PIN_1, steps[currentStep][0]);
            gpio_put(MOTOR_PIN_2, steps[currentStep][1]);
            gpio_put(MOTOR_PIN_3, steps[currentStep][2]);
            gpio_put(MOTOR_PIN_4, steps[currentStep][3]);
            currentStep = nextStep(currentStep, motorMode == MotorMode::Backward);
            sleep_ms(motorSpeed);
        } else {
            sleep_ms(100);
        }
    }

    serverDeinit();
    return 0;
}

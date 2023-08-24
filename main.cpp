/**
 * Copyright (c) 2022 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

// This template is based on the "access_point" exemple from https://github.com/raspberrypi/pico-examples/tree/master/pico_w/wifi/access_point
extern "C" {
    #include "server.h"

}

uint32_t blinkInterval = 500;

int main() {
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

    // Edit the webpage.c file to change your web content

    // New way to light the onboard led
    cyw43_gpio_set(&cyw43_state, 0, true);
    
    while(!state->complete) {
        // Do your usual pico stuff here
        cyw43_gpio_set(&cyw43_state, 0, true);
        sleep_ms(blinkInterval);
        cyw43_gpio_set(&cyw43_state, 0, true);
        sleep_ms(blinkInterval);
    }

    serverDeinit();
    return 0;
}

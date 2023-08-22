/**
 * Copyright (c) 2022 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "server.h"

int main() {
    stdio_init_all();
    
    if (cyw43_arch_init()) {
        DEBUG_printf("failed to initialise\n");
        return 1;
    }
    
    int serverInitResult = serverInit("picow_test", "password");
    if(serverInitResult != 0) {
        return serverInitResult;
    }

    cyw43_gpio_set(&cyw43_state, 0, true);
    
    while(!state->complete) {
        sleep_ms(1000);
    }

    serverDeinit();
    return 0;
}

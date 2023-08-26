#pragma once

#include "pico/stdlib.h"

// /!\ This is a big shortcut! Expect some trouble you use more complex variables, or if both cores edit these. (This can be solved with a lock/mutex system) /!\ //
extern volatile bool blinking;
extern volatile uint32_t blinkSpeed;
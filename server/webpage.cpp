#include "webpage.h"
#include "server.h"

#include "LedControlComponent.cpp"
#include "MotorSpeedControlComponent.cpp"
#include "controlVariables.h" // TO REMOVE AFTER TESTS

int page_content(const char *request, const char *params, char *result) {
    int len = 0;
    if (strncmp(request, INDEX_PATH, sizeof(INDEX_PATH) - 1) == 0) {
        // See if the user changed it
        if (params) {
            int led_state;
            int led_param = sscanf(params, LED_PARAM, &led_state);
            if (led_param == 1) {
                if (led_state) {
                    // Turn led on
                    cyw43_gpio_set(&cyw43_state, 0, true);
                } else {
                    // Turn led off
                    cyw43_gpio_set(&cyw43_state, 0, false);
                }
            }

            uint32_t motorInterval;
            int motorInterval_param = sscanf(params, "motorInterval=%d", &motorInterval);
            if (motorInterval_param == 1) {
                blinkInterval = motorInterval;
            }
        }

        // Generate result
        const std::string generatedHtml = LedControlComponent::html_content() + MotorSpeedControlComponent::html_content();

        len = sprintf(result, HTML_PAGE, generatedHtml.c_str());
    }
    return len;
}
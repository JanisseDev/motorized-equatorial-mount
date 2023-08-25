#include "webpage.h"
#include "server.h"

int page_content(const char *request, const char *params, char *result) {
    int len = 0;
    if (strncmp(request, INDEX_PATH, sizeof(INDEX_PATH) - 1) == 0) {
        // Get the state of the led
        bool value;
        cyw43_gpio_get(&cyw43_state, LED_GPIO, &value);
        int led_state = value;

        // See if the user changed it
        if (params) {
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
        }

        // Generate result
        std::vector<std::string> args;
        if (led_state) {
            args = {"ON", "0", "OFF"};
        } else {
            args = {"OFF", "1", "ON"};
        }

        const std::string generatedHtml = "\
<div class='cell'>\
    <p>Led is " + args[0] + "</p>\
    <a href='?led=" + args[1] + "'>Turn led " + args[2] + "</a>\
</div>";

        len = sprintf(result, HTML_PAGE, generatedHtml.c_str());
    }
    return len;
}
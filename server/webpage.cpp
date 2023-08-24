#include "webpage.h"
#include "server.h"

const char* cellHtml = "\
<div class='cell'>\
    <p>Led is %s</p>\
    <a href='?led=%d'>Turn led %s</a>\
</div>";

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

        char generatedHtml[strlen(cellHtml)];
        
        if (led_state) {
            sprintf(generatedHtml, cellHtml, "ON", 0, "OFF");
        } else {
            sprintf(generatedHtml, cellHtml, "OFF", 1, "ON");
        }

        len = sprintf(result, HTML_PAGE, generatedHtml);
    }
    return len;
}
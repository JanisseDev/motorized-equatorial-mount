#include <string>
#include <vector>

#include "server.h"

#define LED_GPIO 0

class LedControlComponent {
    private:
     static std::string generate_content(std::vector<std::string> args) {
        return "\
<div class='cell'>\
    <p>Led is " + args[0] + "</p>\
    <a href='?led=" + args[1] + "'>Turn led " + args[2] + "</a>\
</div>";
    }

    public:
     static std::string html_content()
    {
        // Get the state of the led
        bool led_state;
        cyw43_gpio_get(&cyw43_state, LED_GPIO, &led_state);
        
        // Generate result
        std::vector<std::string> args;
        if (led_state) {
            args = {"ON", "0", "OFF"};
        } else {
            args = {"OFF", "1", "ON"};
        }

        return generate_content(args);
    }
};
#include <string>
#include <vector>

#include "server.h"
#include "controlVariables.h"

class BlinkSpeedControlComponent {
private:
    static std::string generate_content(std::vector<std::string> args) {
        return "\
<div class='cell'>\
    <p>Blink speed is "+args[0]+"ms</p>\
    <a href='?blinkSpeed="+args[1]+"'>Switch to "+args[1]+"ms</a>\
</div>";
    }

public:
    static void check_params(const char *params)
    {
        uint32_t blinkSpeedValue;
        int blinkSpeed_param = sscanf(params, "blinkSpeed=%d", &blinkSpeedValue);
        if (blinkSpeed_param == 1) {
            blinkSpeed = blinkSpeedValue;
        }
    }

    static std::string html_content()
    {   
        // Generate result
        std::vector<std::string> args;
        if (blinkSpeed == 100) {
            args = {std::to_string(blinkSpeed), "500"};
        } else {
            args = {std::to_string(blinkSpeed), "100"};
        }

        return generate_content(args);
    }
};
#include <string>
#include <vector>

#include "server.h"
#include "controlVariables.h"

class BlinkSpeedControlComponent {
private:
    static std::string generate_content(std::vector<std::string> args) {
        return "\
<div class='cell'>\
    <p>Blink speed</p>\
    <div class='switch'>\
        <a "+args[0]+" href='?blinkSpeed=100'>100ms</a>\
        <a "+args[1]+" href='?blinkSpeed=250'>250ms</a>\
        <a "+args[2]+" href='?blinkSpeed=500'>500ms</a>\
    </div>\
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
        switch (blinkSpeed) {
            case 100: args = {"class='selected'", "", ""}; break;
            case 250: args = {"", "class='selected'", ""}; break;
            case 500: args = {"", "", "class='selected'"}; break;
            default: args = {"", "", ""}; break;
        }

        return generate_content(args);
    }
};
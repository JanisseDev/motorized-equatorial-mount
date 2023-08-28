#include <string>
#include <vector>

#include "server.h"
#include "controlVariables.h"

class BlinkingControlComponent {
private:
    static std::string generate_content(std::vector<std::string> args) {
        return "\
<div class='cell'>\
    <p>LED</p>\
    <div class='switch'>\
        <a "+args[0]+" href='?blinking=0'>Fix</a>\
        <a "+args[1]+" href='?blinking=1'>Blink</a>\
    </div>\
</div>";
    }

public:
    static void check_params(const char *params)
    {
        int blinkingValue;
        int blinking_param = sscanf(params, "blinking=%d", &blinkingValue);
        if (blinking_param == 1) {
            blinking = blinkingValue;
        }
    }

    static std::string html_content()
    {
        // Generate result
        std::vector<std::string> args;
        if (blinking) {
            args = {"", "class='selected'"};
        } else {
            args = {"class='selected'", ""};
        }
        
        return generate_content(args);
    }
};
#include <string>
#include <vector>

#include "server.h"
#include "controlVariables.h"

class BlinkingControlComponent {
private:
    static std::string generate_content(std::vector<std::string> args) {
        return "\
<div class='cell'>\
    <p>"+args[0]+" LED</p>\
    <a href='?blinking="+args[1]+"'>Switch to "+args[2]+" LED</a>\
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
            args = {"Blinking", "0", "fixed"};
        } else {
            args = {"Fixed", "1", "blinking"};
        }
        
        return generate_content(args);
    }
};
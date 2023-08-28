#include <string>
#include <vector>

#include "server.h"
#include "controlVariables.h"

class BlinkingControlComponent {
private:
    static std::string generate_content(int selectedOption) {
        const std::string selectedClass = "class='selected'";
        return "\
<div class='cell'>\
    <p>LED</p>\
    <div class='switch'>\
        <a "+((selectedOption==0)?selectedClass:"")+" href='?blinking=0'>Fix</a>\
        <a "+((selectedOption==1)?selectedClass:"")+" href='?blinking=1'>Blink</a>\
    </div>\
</div>";
    }

public:
    static void check_params(const char *params)
    {
        int value;
        int matchCount = sscanf(params, "blinking=%d", &value);
        if (matchCount == 1) {
            blinking = value;
        }
    }

    static std::string html_content()
    {
        // Generate result
        return generate_content(blinking ? 1 : 0);
    }
};
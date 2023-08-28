#include <string>
#include <vector>

#include "server.h"
#include "controlVariables.h"

class MotorModeControlComponent {
private:
    static std::string generate_content(MotorMode currentMode) {
        const std::string selectedClass = "class='selected'";
        return "\
<div class='cell'>\
    <p>Motor mode</p>\
    <div class='switch'>\
        <a "+((motorMode==MotorMode::Backward)?selectedClass:"")+" href='?motorMode=-1'>Backward</a>\
        <a "+((motorMode==MotorMode::Stopped)?selectedClass:"")+" href='?motorMode=0'>Stopped</a>\
        <a "+((motorMode==MotorMode::Forward)?selectedClass:"")+" href='?motorMode=1'>Forward</a>\
    </div>\
</div>";
    }

public:
    static void check_params(const char *params)
    {
        int value;
        int matchCount = sscanf(params, "motorMode=%d", &value);
        if (matchCount == 1) {
            motorMode = (MotorMode)value;
        }
    }

    static std::string html_content()
    {
        // Generate result
        return generate_content(motorMode);
    }
};
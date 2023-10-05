#include <string>
#include <vector>

#include "server.h"
#include "controlVariables.h"

class MotorSpeedControlComponent {
private:
    static std::string generate_content(uint32_t currentValue) {
        return "\
<div class='cell'>\
    <p>Motor speed</p>\
    <form>\
        <input type='number' name='motorSpeed' style='width: 100px;' value='"+std::to_string(currentValue)+"' min='8' max='10000'/>\
        <input type='submit' value='Send'/>\
    </form>\
</div>";
    }

public:
    static void check_params(const char *params)
    {
        uint32_t value;
        int matchCount = sscanf(params, "motorSpeed=%d", &value);
        if (matchCount == 1) {
            motorSpeed = value;
        }
    }

    static std::string html_content()
    {
        // Generate result
        return generate_content(motorSpeed);
    }
};
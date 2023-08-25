#include <string>
#include <vector>

#include "server.h"
#include "controlVariables.h"

class MotorSpeedControlComponent {
    private:
     static std::string generate_content(std::vector<std::string> args) {
        return "\
<div class='cell'>\
    <p>Motor interval is " + args[0] + "</p>\
    <a href='?motorInterval=" + args[1] + "'>" + args[1] + "</a>\
</div>";
    }

    public:
     static std::string html_content()
    {   
        // Generate result
        std::vector<std::string> args;
        if (blinkInterval == 100) {
            args = {blinkInterval, "500"};
        } else {
            args = {blinkInterval, "100"};
        }

        return generate_content(args);
    }
};
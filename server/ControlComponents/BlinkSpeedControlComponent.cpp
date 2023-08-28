#include <string>
#include <vector>

#include "server.h"
#include "controlVariables.h"

class BlinkSpeedControlComponent {
private:
    static std::string generate_content(uint32_t currentValue) {
        return "\
<div class='cell'>\
    <p>Blink speed</p>\
    <form>\
        <input type='number' name='blinkSpeed' list='blinkSpeedDefaultNumbers' style='width: 100px;' value='"+std::to_string(currentValue)+"' min='50'/>\
        <datalist id='blinkSpeedDefaultNumbers'>\
            <option value='100'></option>\
            <option value='250'></option>\
            <option value='500'></option>\
        </datalist>\
        <input type='submit' value='Send'/>\
    </form>\
</div>";
    }

public:
    static void check_params(const char *params)
    {
        uint32_t value;
        int matchCount = sscanf(params, "blinkSpeed=%d", &value);
        if (matchCount == 1) {
            blinkSpeed = value;
        }
    }

    static std::string html_content()
    {
        // Generate result
        return generate_content(blinkSpeed);
    }
};
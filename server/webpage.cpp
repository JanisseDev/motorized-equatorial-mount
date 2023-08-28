#include "webpage.h"
#include "server.h"

#include "BlinkingControlComponent.cpp"
#include "BlinkSpeedControlComponent.cpp"
#include "MotorModeControlComponent.cpp"
#include "MotorSpeedControlComponent.cpp"

int page_content(const char *request, const char *params, std::string *result) {
    int len = 0;
    if (strncmp(request, INDEX_PATH, sizeof(INDEX_PATH) - 1) == 0) {
        // See if the user changed it
        if (params) {
            MotorModeControlComponent::check_params(params);
            MotorSpeedControlComponent::check_params(params);
        }

        // Generate result
        result->clear();
        *result += HTML_HEAD + HTML_START;
        *result += MotorModeControlComponent::html_content() + MotorSpeedControlComponent::html_content();
        *result += HTML_END;
    }
    return len;
}
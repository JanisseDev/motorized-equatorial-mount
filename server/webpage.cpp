#include "webpage.h"
#include "server.h"

#include "LedControlComponent.cpp"
#include "MotorSpeedControlComponent.cpp"

int page_content(const char *request, const char *params, char *result) {
    int len = 0;
    if (strncmp(request, INDEX_PATH, sizeof(INDEX_PATH) - 1) == 0) {
        // See if the user changed it
        if (params) {
            LedControlComponent::check_params(params);
            MotorSpeedControlComponent::check_params(params);
        }

        // Generate result
        const std::string generatedHtml = LedControlComponent::html_content() + MotorSpeedControlComponent::html_content();

        len = sprintf(result, HTML_PAGE, generatedHtml.c_str());
    }
    return len;
}
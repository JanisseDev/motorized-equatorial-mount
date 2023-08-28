#ifndef WEBPAGE_H
#define WEBPAGE_H

#include <string>
#include <vector>

#include "pico/stdlib.h"

#define HTTP_RESPONSE_HEADERS "HTTP/1.1 %d OK\nContent-Length: %d\nContent-Type: text/html; charset=utf-8\nConnection: close\n\n"
#define INDEX_PATH "/index"
#define HTTP_RESPONSE_REDIRECT "HTTP/1.1 302 Redirect\nLocation: http://%s" INDEX_PATH "\n\n"

#define HTML_HEAD "\
<head>\
    <meta charset='utf-8' />\
    <title>Equatorial mount</title>\
    <meta name='viewport' content='width=device-width, initial-scale=1.0'>\
    <style>\
        body                {background-color: rgb(42, 0, 0);}\
        h1, p, a            {color: rgb(223, 143, 143); margin: 0; padding: 0; text-decoration: none;}\
        h1                  {text-align: center; font-size: 20px;}\
        #title              {margin: 20px;}\
        p                   {font-size: 16px;}\
        .grid               {display: flex; flex-wrap: wrap; gap: 8px;}\
        .cell               {display: flex; padding: 12px; min-height: 80px; min-width: 80px; justify-content: center; flex-direction: column; align-items: center; flex-grow: 1; gap: 4px; border-width: 1px; border-color: rgb(133, 77, 77); border-style: solid; border-radius: 8px;}\
        .switch             {display: flex; flex-direction: row; border-width: 0.5px; border-color: rgb(110, 0, 0); border-style: solid; border-radius: 4px;}\
        .switch *           {padding: 4px;}\
        .switch .selected   {background-color: rgb(110, 0, 0); border-radius: 3px;}\
    </style>\
</head>"

#define HTML_BODY "\
<body>\
    <h1 id='title'>Motorized equatorial mount</h1>\
    <div class='grid'>%s</div>\
    </div>\
</body>"

#define HTML_PAGE "<html>" HTML_HEAD HTML_BODY "</html>"

int page_content(const char *request, const char *params, char *result);

#endif
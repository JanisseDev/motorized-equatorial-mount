cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

include(pico_extras_import_optional.cmake)

set(PICO_BOARD pico_w)
set(PROJECT_NAME motorized_equatorial_mount)
project(${PROJECT_NAME} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(PICO_CXX_ENABLE_EXCEPTIONS 1)
set(PICO_CXX_ENABLE_RTTI 1)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

add_executable(${PROJECT_NAME}
        main.cpp
        dhcpserver/dhcpserver.cpp
        dnsserver/dnsserver.cpp
        server/server.cpp
        server/webpage.cpp
        server/ControlComponents/LedControlComponent.cpp
        )

target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts
        ${CMAKE_CURRENT_LIST_DIR}/dhcpserver
        ${CMAKE_CURRENT_LIST_DIR}/dnsserver
        ${CMAKE_CURRENT_LIST_DIR}/server
        ${CMAKE_CURRENT_LIST_DIR}/server/ControlComponents
        )

target_link_libraries(${PROJECT_NAME}
        pico_cyw43_arch_lwip_threadsafe_background
        pico_stdlib
        )

pico_add_extra_outputs(${PROJECT_NAME})

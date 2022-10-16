cmake_minimum_required(VERSION 3.12)

include(cmake/pico_sdk_import.cmake)

project(pico_samples C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(main)
target_sources(main PRIVATE src/main.c)
target_link_libraries(main pico_stdlib)
pico_enable_stdio_usb(main 1)
pico_enable_stdio_uart(main 1)
pico_add_extra_outputs(main)


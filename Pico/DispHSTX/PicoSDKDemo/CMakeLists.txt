cmake_minimum_required(VERSION 3.18...3.28)

set(PICOTOOL_FORCE_FETCH_FROM_GIT ON)
set(PICO_SDK_PATH ${CMAKE_CURRENT_LIST_DIR}/../../../../pico-sdk)

# Set platform, board, and compiler
# ARM
set(PICO_PLATFORM rp2350)
# RISC-V
# set(PICO_PLATFORM rp2350-riscv)
# set(PICO_TOOLCHAIN_PATH ${CMAKE_CURRENT_LIST_DIR}/../../../../corev-openhw-gcc-macos-20240530)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

include(pico_sdk_import.cmake)

project(PicoSDKDemo C CXX ASM)

pico_sdk_init()

add_subdirectory("../../.." "DispHSTX")

add_executable(PicoSDKDemo
        img/DispHSTX_logo.cpp
        img/Img532x400_16b.cpp
        img/pattern.cpp
        img/Img1b.cpp
        img/Img2b.cpp
        img/Img3b.cpp
        img/Img4b.cpp
        img/Img6b.cpp
        img/Img8b.cpp
        img/Img12b.cpp
        img/Img15b.cpp
        img/Img16b.cpp

        src/main.cpp
)

target_link_libraries(PicoSDKDemo
        pico_stdlib
        DispHSTX
)

target_include_directories(PicoSDKDemo PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_compile_options(PicoSDKDemo PRIVATE -include ${CMAKE_CURRENT_LIST_DIR}/config.h)

# RISC-V
# target_compile_definitions(PicoSDKDemo PRIVATE RISCV=1)

pico_enable_stdio_usb(PicoSDKDemo 1)
pico_enable_stdio_uart(PicoSDKDemo 0)
pico_add_extra_outputs(PicoSDKDemo)

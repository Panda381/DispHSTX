cmake_minimum_required(VERSION 3.18...3.28)
include(pico_sdk_import.cmake)

project(DispHSTX C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(PICO_PLATFORM rp2350)

pico_sdk_init()

add_library(DispHSTX INTERFACE)

target_sources(DispHSTX INTERFACE
		${CMAKE_CURRENT_LIST_DIR}/_display/disphstx/disphstx.h

		${CMAKE_CURRENT_LIST_DIR}/_display/disphstx/disphstx_dvi_m33.S
		${CMAKE_CURRENT_LIST_DIR}/_display/disphstx/disphstx_vga_m33.S
		${CMAKE_CURRENT_LIST_DIR}/_display/disphstx/disphstx_dvi_riscv.S
		${CMAKE_CURRENT_LIST_DIR}/_display/disphstx/disphstx_vga_riscv.S

		${CMAKE_CURRENT_LIST_DIR}/_display/disphstx/disphstx_dvi.c
		${CMAKE_CURRENT_LIST_DIR}/_display/disphstx/disphstx_dvi_render.c
		${CMAKE_CURRENT_LIST_DIR}/_display/disphstx/disphstx_vga.c
		${CMAKE_CURRENT_LIST_DIR}/_display/disphstx/disphstx_vga_render.c
		${CMAKE_CURRENT_LIST_DIR}/_display/disphstx/disphstx_vmode.c
		${CMAKE_CURRENT_LIST_DIR}/_display/disphstx/disphstx_vmode_simple.c
		${CMAKE_CURRENT_LIST_DIR}/_display/disphstx/disphstx_vmode_format.c
		${CMAKE_CURRENT_LIST_DIR}/_display/disphstx/disphstx_vmode_time.c
		${CMAKE_CURRENT_LIST_DIR}/_display/disphstx/disphstx_picolibsk.c

		${CMAKE_CURRENT_LIST_DIR}/_font/font_boldB_8x14.c
		${CMAKE_CURRENT_LIST_DIR}/_font/font_boldB_8x16.c
		${CMAKE_CURRENT_LIST_DIR}/_font/font_bold_8x14.c
		${CMAKE_CURRENT_LIST_DIR}/_font/font_bold_8x16.c
		${CMAKE_CURRENT_LIST_DIR}/_font/font_bold_8x8.c
		${CMAKE_CURRENT_LIST_DIR}/_font/font_cond_6x8.c
		${CMAKE_CURRENT_LIST_DIR}/_font/font_game_8x8.c
		${CMAKE_CURRENT_LIST_DIR}/_font/font_ibmtiny_8x8.c
		${CMAKE_CURRENT_LIST_DIR}/_font/font_ibm_8x14.c
		${CMAKE_CURRENT_LIST_DIR}/_font/font_ibm_8x16.c
		${CMAKE_CURRENT_LIST_DIR}/_font/font_ibm_8x8.c
		${CMAKE_CURRENT_LIST_DIR}/_font/font_italic_8x8.c
		${CMAKE_CURRENT_LIST_DIR}/_font/font_thin_8x8.c
		${CMAKE_CURRENT_LIST_DIR}/_font/font_tiny_5x8.c

		${CMAKE_CURRENT_LIST_DIR}/_lib/src/lib_drawcan.c
		${CMAKE_CURRENT_LIST_DIR}/_lib/src/lib_drawcan1.c
		${CMAKE_CURRENT_LIST_DIR}/_lib/src/lib_drawcan2.c
		${CMAKE_CURRENT_LIST_DIR}/_lib/src/lib_drawcan3.c
		${CMAKE_CURRENT_LIST_DIR}/_lib/src/lib_drawcan4.c
		${CMAKE_CURRENT_LIST_DIR}/_lib/src/lib_drawcan6.c
		${CMAKE_CURRENT_LIST_DIR}/_lib/src/lib_drawcan8.c
		${CMAKE_CURRENT_LIST_DIR}/_lib/src/lib_drawcan12.c
		${CMAKE_CURRENT_LIST_DIR}/_lib/src/lib_drawcan16.c
		${CMAKE_CURRENT_LIST_DIR}/_lib/src/lib_rand.c
)

target_include_directories(DispHSTX INTERFACE ${CMAKE_CURRENT_LIST_DIR}/_display/disphstx/)
target_link_libraries(DispHSTX INTERFACE
		pico_stdlib
		pico_multicore
		hardware_clocks
		hardware_gpio
		hardware_dma
)




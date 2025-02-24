ifeq (${OS},Windows_NT)
CSRC += ${PICOLIBSDK_DISPLAY_DIR}/display.c
else
CSRC += ${PICOLIBSDK_DISPLAY_DIR}/disphstx/disphstx_dvi.c
CSRC += ${PICOLIBSDK_DISPLAY_DIR}/disphstx/disphstx_dvi_render.c
CSRC += ${PICOLIBSDK_DISPLAY_DIR}/disphstx/disphstx_vga.c
CSRC += ${PICOLIBSDK_DISPLAY_DIR}/disphstx/disphstx_vga_render.c
CSRC += ${PICOLIBSDK_DISPLAY_DIR}/disphstx/disphstx_vmode.c
CSRC += ${PICOLIBSDK_DISPLAY_DIR}/disphstx/disphstx_vmode_simple.c
CSRC += ${PICOLIBSDK_DISPLAY_DIR}/disphstx/disphstx_vmode_format.c
CSRC += ${PICOLIBSDK_DISPLAY_DIR}/disphstx/disphstx_vmode_time.c
CSRC += ${PICOLIBSDK_DISPLAY_DIR}/disphstx/disphstx_picolibsk.c
endif

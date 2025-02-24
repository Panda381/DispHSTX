
ifeq (${OS},Windows_NT)
CSRC += ${PICOLIBSDK_LIB_DIR}/lib.c
else
CSRC += ${PICOLIBSDK_LIB_DIR}/src/lib_drawcan.c
CSRC += ${PICOLIBSDK_LIB_DIR}/src/lib_drawcan1.c
CSRC += ${PICOLIBSDK_LIB_DIR}/src/lib_drawcan2.c
CSRC += ${PICOLIBSDK_LIB_DIR}/src/lib_drawcan3.c
CSRC += ${PICOLIBSDK_LIB_DIR}/src/lib_drawcan4.c
CSRC += ${PICOLIBSDK_LIB_DIR}/src/lib_drawcan6.c
CSRC += ${PICOLIBSDK_LIB_DIR}/src/lib_drawcan8.c
CSRC += ${PICOLIBSDK_LIB_DIR}/src/lib_drawcan12.c
CSRC += ${PICOLIBSDK_LIB_DIR}/src/lib_drawcan16.c
CSRC += ${PICOLIBSDK_LIB_DIR}/src/lib_rand.c
endif

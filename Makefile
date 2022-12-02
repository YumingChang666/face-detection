# Set kernel name
KERNEL_NAME = face_detect

# Set host source and headers
HOST_SRC_CPP = ./src/host/face_detect_host.c ./src/host/utils.c ./src/host/check_result.c ./src/host/image.c
HOST_SRC_H   = ./src/host/utils.h ./src/host/check_result.h ./src/host/typedefs.h ./src/host/image0_320_240.h \
               ./src/host/image.h
DATA         = 


# Set kernel file
SW_KERNEL_SRC = ./src/sw/face_detect_sw.c
SW_KERNEL_H = ./src/host/typedefs.h ./src/sw/*.h

# Set opencl kernel arguments
OCL_KERNEL_ARGS = --max_memory_ports all --report_level 2 -I$(shell pwd)/src/

#-------------------------
# Leave the rest to harness
#-------------------------
include ./harness/harness.mk


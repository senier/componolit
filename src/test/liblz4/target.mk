TARGET = liblz4_test

LIBLZ4_DIR = $(call select_from_ports,liblz4)/lz4/lib

vpath %.c $(LIBLZ4_DIR)/tests

INC_DIR += $(LIBLZ4_DIR)/programs
SRC_CC += main.cc fuzzer.c
LIBS   += libc stdcxx liblz4

# For some reason, util.h does no include <string.h> while using strlen() etc.
CC_OPT = -include string.h

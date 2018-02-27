TARGET = liblz4_test

LIBLZ4_TESTS_DIR = $(call select_from_ports,liblz4)/lz4/lib/tests
LIBLZ4_PROGRAMS_DIR = $(call select_from_ports,liblz4)/lz4/lib/programs

vpath %.c $(LIBLZ4_TESTS_DIR)

INC_DIR += $(LIBLZ4_PROGRAMS_DIR)
SRC_CC += main.cc fuzzer.c
LIBS   += libc stdcxx liblz4

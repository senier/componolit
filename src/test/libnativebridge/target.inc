SRC_CC += main.cc
CC_OPT += -g -Wall -Werror -fno-builtin

LIBNATIVEBRIDGE_TESTS_DIR := $(call select_from_ports,libnativebridge)/libnativebridge/libnativebridge/tests
vpath %.cpp $(LIBNATIVEBRIDGE_TESTS_DIR)
vpath %.cc $(REP_DIR)/src/test/libnativebridge

INC_DIR += $(LIBNATIVEBRIDGE_TESTS_DIR)

LIBS += libc stdcxx posix liblog gtest libnativehelper libnativebridge

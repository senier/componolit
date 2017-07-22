LIBNATIVEBRIDGE_TESTS_DIR = $(call select_from_ports,libnativebridge)/libnativebridge/libnativebridge/tests

vpath %.cpp $(LIBNATIVEBRIDGE_TESTS_DIR)
INC_DIR += $(LIBNATIVEBRIDGE_TESTS_DIR)

LIBS += libc libnativebridge libnativehelper

SHARED_LIB = yes

LIBNATIVEBRIDGE_TESTS_DIR = $(call select_from_ports,core)/system/core/libnativebridge/tests

vpath %.cpp $(LIBNATIVEBRIDGE_TESTS_DIR)
INC_DIR += $(LIBNATIVEBRIDGE_TESTS_DIR)

LIBS += libc libnativebridge libnativehelper libcore_includes

SHARED_LIB = yes

CC_CXX_WARN_STRICT =

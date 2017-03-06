LIBNATIVEHELPER_DIR := $(call select_from_ports,libnativehelper)/libnativehelper

SRC_CC = JNIHelp.cpp JniConstants.cpp toStringArray.cpp JniInvocation.cpp

vpath %.cpp $(LIBNATIVEHELPER_DIR)

INC_DIR += $(LIBNATIVEHELPER_DIR)/include/nativehelper

# FIXME: We only need the header file of top-level core
# This works as liblog is a dependency and triggers the
# checkout of system/core. We should create a dummy core
# library. I have not figured out how to do this without
# building a library, though.
INC_DIR += $(call select_from_ports,liblog)/system/core/include


LIBS       += libc stdcxx liblog
SHARED_LIB  = yes

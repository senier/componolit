TARGET = libnativebridge_test

SRC_CC += \
	main.cc \
	CodeCacheCreate_test.cpp \
	CodeCacheExists_test.cpp \
	CodeCacheStatFail_test.cpp \
	CompleteFlow_test.cpp \
	DummyNativeBridge3.cpp \
	InvalidCharsNativeBridge_test.cpp \
	NativeBridge3CreateNamespace_test.cpp \
	NativeBridge3GetError_test.cpp \
	NativeBridge3InitAnonymousNamespace_test.cpp \
	NativeBridge3IsPathSupported_test.cpp \
	NativeBridge3LoadLibraryExt_test.cpp \
	NativeBridge3UnloadLibrary_test.cpp \
	NativeBridgeVersion_test.cpp \
	NeedsNativeBridge_test.cpp \
	PreInitializeNativeBridgeFail1_test.cpp \
	ReSetupNativeBridge_test.cpp \
	UnavailableNativeBridge_test.cpp \
	ValidNameNativeBridge_test.cpp \

CC_OPT = -g -Wall -Werror -fno-builtin

LIBNATIVEBRIDGE_TESTS_DIR := $(call select_from_ports,libnativebridge)/libnativebridge/libnativebridge/tests
vpath %.cpp $(LIBNATIVEBRIDGE_TESTS_DIR)
INC_DIR += $(LIBNATIVEBRIDGE_TESTS_DIR)

LIBS += libc stdcxx posix liblog gtest libnativehelper libnativebridge

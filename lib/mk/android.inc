ANDROID_OUTPUT := $(LIB_CACHE_DIR)/$(LIB)/android.mk

check_android_vars := $(call _assert,$(ANDROID_BASEDIR), ANDROID_BASEDIR not set)

ifneq ($(called_from_lib_mk),yes)

check_android_vars := $(call _assert,$(ANDROID_BUILDFILES), ANDROID_BUILDFILES not set)
check_android_vars := $(call _assert,$(ANDROID_SECTIONS), ANDROID_SECTIONS not set)

$(ANDROID_OUTPUT):
	mkdir -p $(LIB_CACHE_DIR)/$(LIB)
	$(call select_from_repositories,tool/gnoos) \
	--basedir $(ANDROID_BASEDIR) \
	--prefix $(LIB)_ \
	--output $@ \
	$(addprefix --input ,$(ANDROID_BUILDFILES)) \
	$(ANDROID_SECTIONS)

all: $(ANDROID_OUTPUT)

endif

include $(ANDROID_OUTPUT)

SHARED_LIB  = yes

SRC_C  = $(filter %.c,$($(LIB)_SRCS))
SRC_CC = $(filter %.cpp,$($(LIB)_SRCS))

CC_OPT  = $($(LIB)_CFLAGS)
CPP_OPT = $($(LIB)_CFLAGS)

LIBS       += libc cxx $($(LIB)_SHARED_LIBS)
INC_DIR    += $(addprefix $(ANDROID_BASEDIR)/,$(ANDROID_INCLUDES))

vpath % $(addprefix $(ANDROID_BASEDIR)/,$(ANDROID_SOURCES))

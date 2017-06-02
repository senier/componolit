ifeq ($(called_from_lib_mk),yes)

ANDROID_OUTPUT := $(LIB_CACHE_DIR)/$(LIB)/android.mk

check_android_vars := $(call _assert,$(ANDROID_BASEDIR), ANDROID_BASEDIR not set)
check_android_vars := $(call _assert,$(ANDROID_BUILDFILES), ANDROID_BUILDFILES not set)
check_android_vars := $(call _assert,$(ANDROID_SECTIONS), ANDROID_SECTIONS not set)

GNOOS := \
	$(call select_from_repositories,tool/gnoos) \
	--basedir $(ANDROID_BASEDIR) \
	--prefix $(LIB)_ \
	--output $(ANDROID_OUTPUT) \
	$(addprefix --input ,$(ANDROID_BUILDFILES)) \
	$(ANDROID_SECTIONS)

$(eval $(shell $(GNOOS)))

include $(ANDROID_OUTPUT)

CC_OPT  = $($(LIB)_CFLAGS)
CPP_OPT = $($(LIB)_CFLAGS)

SRC_C   = $(filter %.c,$($(LIB)_SRCS))
SRC_CPP = $(filter %.cpp,$($(LIB)_SRCS))

SHARED_LIB  = yes
LIBS       += libc cxx
INC_DIR    += $(addprefix $(ANDROID_BASEDIR)/,$(ANDROID_INCLUDES))

vpath % $(addprefix $(ANDROID_BASEDIR)/,$(ANDROID_SOURCES))

endif

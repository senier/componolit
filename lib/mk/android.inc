ANDROID_OUTPUT := $(LIB_CACHE_DIR)/$(LIB)/android.mk

check_android_vars := $(call _assert,$(ANDROID_BASEDIR), ANDROID_BASEDIR not set)
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

include $(ANDROID_OUTPUT)

ANDROID_LIBS = $($(LIB)_SHARED_LIBS)

SHARED_LIB  = yes

SRC_C   = $(filter %.c,$($(LIB)_SRCS))
CC_OPT  = $($(LIB)_CFLAGS)
SRC_CC  = $(filter %.cpp,$($(LIB)_SRCS))
CPP_OPT = $($(LIB)_CFLAGS)

INC_DIR    += $(addprefix $(ANDROID_BASEDIR)/,$(ANDROID_INCLUDES))

vpath % $(addprefix $(ANDROID_BASEDIR)/,$(ANDROID_SOURCES))

MISSING_LIBS = $(filter-out $(LIBS), $(ANDROID_LIBS))

ifneq ($(MISSING_LIBS),)
$(error Missing Android libraries for $(LIB): $(MISSING_LIBS))
endif

LIBS += libc cxx

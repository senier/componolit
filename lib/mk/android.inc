ANDROID_OUTPUT := $(LIB_CACHE_DIR)/$(LIB)/android.mk

check_android_vars := $(call _assert,$(ANDROID_BASEDIR), ANDROID_BASEDIR not set for $(LIB))
check_android_vars := $(call _assert,$(ANDROID_SECTIONS), ANDROID_SECTIONS not set for $(LIB))

ANDROID_INCLUDES   ?= . include
ANDROID_SOURCES    ?= .
ANDROID_BUILDFILES ?= Android.bp

$(ANDROID_OUTPUT): $(addprefix $(ANDROID_BASEDIR)/,$(ANDROID_BUILDFILES))
	mkdir -p $(LIB_CACHE_DIR)/$(LIB)
	$(call select_from_repositories,tool/gnoos) \
	--basedir $(ANDROID_BASEDIR) \
	--prefix $(LIB)_ \
	--output $@ \
	$(addprefix --input ,$(ANDROID_BUILDFILES)) \
	$(ANDROID_SECTIONS)
	@echo "$(LIB)_BASEDIR = $(ANDROID_BASEDIR)" >> $@

all: $(ANDROID_OUTPUT)

include $(ANDROID_OUTPUT)

SHARED_LIB  = yes

SRC_C   = $(filter %.c,$($(LIB)_SRCS))
CC_OPT  = $($(LIB)_CFLAGS)
SRC_CC  = $(filter %.cpp,$($(LIB)_SRCS))
CPP_OPT = $($(LIB)_CFLAGS)

INC_DIR    += $(addprefix $(ANDROID_BASEDIR)/,$(ANDROID_INCLUDES))

vpath % $(addprefix $(ANDROID_BASEDIR)/,$(ANDROID_SOURCES))

# Include these libraries by default
LIBS += libc cxx stdcxx $($(LIB)_SHARED_LIBS)

$(warning [31mAndroid libraries for $(LIB): $(LIBS)[39m)

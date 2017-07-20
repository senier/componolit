ifneq ($(ANDROID_NAME),)

check_android_vars := $(call _assert,$(ANDROID_PORT), ANDROID_PORT not set for $(ANDROID_NAME))
check_android_vars := $(call _assert,$(ANDROID_SECTIONS), ANDROID_SECTIONS not set for $(ANDROID_NAME))
check_android_vars := $(call _assert,$(ANDROID_BUILDTYPE), ANDROID_BUILDTYPE not set for $(ANDROID_NAME))

ANDROID_OUTPUT := $(LIB_CACHE_DIR)/$(ANDROID_BUILDTYPE)/$(ANDROID_NAME)/android.mk

ANDROID_INCLUDES   ?= . include
ANDROID_SOURCES    ?= .
ANDROID_BUILDFILES ?= Android.bp

ANDROID_PORTDIR     = $(call select_from_ports,$(ANDROID_PORT))
check_android_vars := $(call _assert,$(ANDROID_PORTDIR), Port $(ANDROID_PORT) not found for $(ANDROID_NAME))

ANDROID_BASEDIR		= $(ANDROID_PORTDIR)/$(ANDROID_DIR)

COMMAND := \
	mkdir -p $(dir $(ANDROID_OUTPUT)) && \
	$(call select_from_repositories,tool/gnoos) \
		--basedir $(ANDROID_BASEDIR) \
		--prefix $(ANDROID_NAME)_ \
		--output $(ANDROID_OUTPUT) \
		$(addprefix --input ,$(ANDROID_BUILDFILES)) \
		$(ANDROID_SECTIONS) && \
	echo "$(ANDROID_NAME)_BASEDIR = $(ANDROID_BASEDIR)" >> $(ANDROID_OUTPUT) && \
	echo "$(ANDROID_NAME)_EXPORT_INCLUDE_DIRS += $(ANDROID_INCLUDES)" >> $(ANDROID_OUTPUT)

DUMMY := $(shell $(COMMAND))

include $(ANDROID_OUTPUT)

SRC_C   = $(filter-out $(ANDROID_EXCLUDE_C),$(filter %.c,$($(ANDROID_NAME)_SRCS)))
SRC_CC  = $(filter-out $(ANDROID_EXCLUDE_CC),$(filter %.cpp,$($(ANDROID_NAME)_SRCS)))
CC_OPT  = -Werror -D__GENODE__ $($(ANDROID_NAME)_CFLAGS)

INC_DIR := $(INC_DIR) $(addprefix $(ANDROID_BASEDIR)/,$($(ANDROID_NAME)_EXPORT_INCLUDE_DIRS))

vpath % $(addprefix $(ANDROID_BASEDIR)/,$(ANDROID_SOURCES))

# Include these libraries by default
LIBS += libc cxx stdcxx pthread $($(ANDROID_NAME)_SHARED_LIBS)

else
$(error ANDROID_NAME not set)
endif

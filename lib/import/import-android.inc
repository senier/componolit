secondlast = $(if $(word 3,$(1)),$(call secondlast,$(wordlist 2,$(words $(1)),$(1))),$(firstword $(1)))
ANDROID_LIB := $(patsubst import-%.mk,%,$(call secondlast,$(notdir $(MAKEFILE_LIST))))

include $(LIB_CACHE_DIR)/lib/$(ANDROID_LIB)/android.mk
INC_DIR := $(INC_DIR) $(addprefix $($(ANDROID_LIB)_BASEDIR)/,$($(ANDROID_LIB)_EXPORT_INCLUDE_DIRS))

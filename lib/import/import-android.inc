ifeq ($(ANDROID_LIB),)
$(error ANDROID_LIB not set)
endif

-include $(LIB_CACHE_DIR)/lib/$(ANDROID_LIB)/android.mk
INC_DIR := $(INC_DIR) $(addprefix $($(ANDROID_LIB)_BASEDIR)/,$($(ANDROID_LIB)_EXPORT_INCLUDE_DIRS))

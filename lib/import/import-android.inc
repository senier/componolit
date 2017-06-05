ifneq ($(ANDROID_LIB),)
-include $(LIB_CACHE_DIR)/$(ANDROID_LIB)/android.mk
INC_DIR += $(addprefix $($(ANDROID_LIB)_$(BASEDIR)),$($(ANDROID_LIB)_EXPORT_INCLUDE_DIRS))
endif

ANDROID_NAME = $(TARGET)
ANDROID_BUILDTYPE = prg
include $(call select_from_repositories,lib/mk/android.inc)

ifneq ($(TARGET), $($(ANDROID_NAME)_NAME))
$(warning TARGET differs from build file: TARGET=$(TARGET), build file=$($(ANDROID_NAME)_NAME))
endif

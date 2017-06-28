ANDROID_NAME = $(LIB)
ANDROID_BUILDTYPE = lib
include $(call select_from_repositories,lib/mk/android.inc)
SHARED_LIB  = yes


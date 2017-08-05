ANDROID_PORT	 = core
ANDROID_DIR		 = /system/core/libbacktrace
ANDROID_SECTIONS = /cc_library[@name=libbacktrace]

include $(call select_from_repositories,lib/mk/android-lib.inc)

#CC_OPT += -Wno-unused-variable -Wno-unused-function

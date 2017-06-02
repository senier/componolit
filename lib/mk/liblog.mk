ANDROID_BASEDIR    = $(call select_from_ports,liblog)/system/core
ANDROID_INCLUDES   = include liblog liblog/include
ANDROID_SOURCES    = liblog
ANDROID_BUILDFILES = liblog/Android.bp
ANDROID_SECTIONS   = /cc_library[@name=liblog] /cc_library[@name=liblog]/target/host

include $(call select_from_repositories,lib/mk/android.inc)

CC_OPT += -Wno-unused-variable -Wno-unused-function

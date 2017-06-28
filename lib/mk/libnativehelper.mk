ANDROID_PORT	   = libnativehelper
ANDROID_DIR		   = libnativehelper
ANDROID_INCLUDES   = include/nativehelper
ANDROID_BUILDFILES = Android.bp
ANDROID_SECTIONS   = /cc_library[@name=libnativehelper]

include $(call select_from_repositories,lib/mk/android-lib.inc)

# FIXME: We only need the header file of top-level core
# This works as liblog is a dependency and triggers the
# checkout of system/core. We should create a dummy core
# library. I have not figured out how to do this without
# building a library, though.
INC_DIR += $(call select_from_ports,liblog)/system/core/include

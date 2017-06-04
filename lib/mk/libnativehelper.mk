ANDROID_BASEDIR    = $(call select_from_ports,libnativehelper)
ANDROID_INCLUDES   = libnativehelper/include/nativehelper
ANDROID_SOURCES    = libnativehelper
ANDROID_BUILDFILES = libnativehelper/Android.bp
ANDROID_SECTIONS   = /cc_library[@name=libnativehelper]

LIBS += liblog stdcxx

include $(call select_from_repositories,lib/mk/android.inc)

# FIXME: We only need the header file of top-level core
# This works as liblog is a dependency and triggers the
# checkout of system/core. We should create a dummy core
# library. I have not figured out how to do this without
# building a library, though.
INC_DIR += $(call select_from_ports,liblog)/system/core/include

ANDROID_PORT = libnativebridge
ANDROID_DIR = libnativebridge/libnativebridge
ANDROID_SECTIONS = /cc_library[@name=libnativebridge]

include $(call select_from_repositories,lib/mk/android-lib.inc)

# libnativebridge includes jni.h which is provided by libnativehelper. As it
# is not a dependency in Android.bp, we need to add it manually.
LIBS += libnativehelper

# Pretend to build on apple to get rid of bind-mount stuff. FIXME: We should
# create a patch against libnativebridge instead.
CC_OPT += -D__APPLE__

# GetNativeBridgeStateString does not have a default return value.
CC_OPT += -Wno-error=return-type

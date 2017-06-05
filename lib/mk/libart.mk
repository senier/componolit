ANDROID_BASEDIR    = $(call select_from_ports,libart)
ANDROID_BUILDFILES = art/build/Android.bp art/runtime/Android.bp
ANDROID_SECTIONS   = /art_cc_library[@name=libart]
ANDROID_BUILDFILES = art/build/Android.bp art/runtime/Android.bp

LIBS += stdcxx libbacktrace

include $(call select_from_repositories,lib/mk/android.inc)

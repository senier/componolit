ANDROID_PORT	   = libart
ANDROID_BUILDFILES = art/build/Android.bp art/runtime/Android.bp
ANDROID_SECTIONS   = /art_cc_library[@name=libart]

include $(call select_from_repositories,lib/mk/android-lib.inc)

TARGET = libart_test

ANDROID_PORT	 = libart
ANDROID_DIR		 = art
ANDROID_BUILDFILES = build/Android.bp test/Android.bp
ANDROID_SECTIONS = /art_cc_test_library[@name=libarttest]

include $(call select_from_repositories,lib/mk/android-prg.inc)

SRC_CC += main.cc
LIBS   += gtest posix

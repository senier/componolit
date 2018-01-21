TARGET = libbase_test

ANDROID_PORT	 = core
ANDROID_DIR		 = system/core/base
ANDROID_SECTIONS = /cc_test[@name=libbase_test]

include $(call select_from_repositories,lib/mk/android-prg.inc)

SRC_CC += main.cc
LIBS   += gtest

TARGET = libunwind_test

ANDROID_PORT	 = libunwind
ANDROID_DIR		 = libunwind
ANDROID_SECTIONS = /cc_test[@name=libunwind-unit-tests]

include $(call select_from_repositories,lib/mk/android-prg.inc)

SRC_CC += main.cc
LIBS   += gtest posix

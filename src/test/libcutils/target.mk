TARGET = libcutils_test

ANDROID_PORT	 = libcutils
ANDROID_DIR		 = libcutils/libcutils/tests
ANDROID_SECTIONS = /cc_test[@name=libcutils_test]

include $(call select_from_repositories,lib/mk/android-prg.inc)

CC_OPT = -Wall
SRC_CC += main.cc
LIBS   += gtest posix

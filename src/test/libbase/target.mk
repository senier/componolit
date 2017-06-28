TARGET = libbase_test

ANDROID_PORT	 = libbase
ANDROID_DIR		 = system/core/base
ANDROID_SECTIONS = /cc_test[@name=libbase_test]

LIBS   += gtest
SRC_CC += main.cc
CC_OPT += -DO_CLOEXEC=0

include $(call select_from_repositories,lib/mk/android-prg.inc)

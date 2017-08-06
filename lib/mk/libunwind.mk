ANDROID_PORT = libunwind
ANDROID_DIR = libunwind
ANDROID_SECTIONS = /cc_library[@name=libunwind] /cc_library[@name=libunwind]/arch/$(ANDROID_ARCH)
ANDROID_EXCLUDE_OPT = -Wno-\#pragma-messages

include $(call select_from_repositories,lib/mk/android-lib.inc)

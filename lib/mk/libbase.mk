ANDROID_PORT	 = libbase
ANDROID_DIR  	 = system/core/base
ANDROID_SECTIONS = /cc_library[@name=libbase] /cc_library[@name=libbase]/target/linux_bionic

include $(call select_from_repositories,lib/mk/android-lib.inc)

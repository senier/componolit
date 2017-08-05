ANDROID_PORT     = core
ANDROID_DIR      = system/core/libbacktrace
ANDROID_SECTIONS = /cc_library[@name=libbacktrace] /cc_library[@name=libbacktrace]/target/android

include $(call select_from_repositories,lib/mk/android-lib.inc)

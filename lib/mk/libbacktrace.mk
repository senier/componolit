ANDROID_BASEDIR    = $(call select_from_ports,liblog)/system/core/libbacktrace
ANDROID_SECTIONS   = /cc_library[@name=libbacktrace] /cc_library[@name=libbacktrace]/target/linux

LIBS += stdcxx libbase

include $(call select_from_repositories,lib/mk/android.inc)

#CC_OPT += -Wno-unused-variable -Wno-unused-function

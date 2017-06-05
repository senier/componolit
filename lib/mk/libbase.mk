ANDROID_BASEDIR  = $(call select_from_ports,libbase)/system/core/base
# Configure additional include paths
# ANDROID_INCLUDES = 
ANDROID_SECTIONS = /cc_library[@name=libbase] #/cc_library[@name=libbase]/target/host
include $(call select_from_repositories,lib/mk/android.inc)

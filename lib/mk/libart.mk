ANDROID_PORT = libart
ANDROID_DIR = art
ANDROID_INCLUDES = runtime runtime/arch
ANDROID_SOURCES = runtime
ANDROID_BUILDFILES = test/Android.bp build/Android.bp runtime/Android.bp
ANDROID_SECTIONS = \
	/art_cc_library[@name=libart] \
	/art_cc_library[@name=libart]/arch/$(ANDROID_ARCH)

ANDROID_EXCLUDE_OPT = \
	-Wimplicit-fallthrough \
	-Wint-to-void-pointer-cast \
	-Wthread-safety \
	-Wthread-safety-negative \
	-Wunreachable-code-break \
	-Wunreachable-code-return \
	-Wused-but-marked-unused

include $(call select_from_repositories,lib/mk/android-lib.inc)

# Taken from build/art.go
CC_OPT += -DIMT_SIZE=43
CC_OPT += -DART_DEFAULT_GC_TYPE_IS_CMS

# Code contains multi-line comments
CC_OPT += -Wno-error=comment

LIBS += valgrind dlmalloc

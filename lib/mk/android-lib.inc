# Override -fvisibility=protected and -fvisiblity=hidden set in Android.bp, as this yields
# linking errors in the form of:
#    genode-x86-ld: arch/arm/instruction_set_features_arm.o: relocation R_X86_64_PC32 against \
#    	protected symbol `_ZNK3art25ArmInstructionSetFeatures17GetInstructionSetEv' \
#    	can not be used when making a shared object
# I don't fully understand the issue, yet.
ANDROID_EXCLUDE_OPT += -fvisibility=hidden -fvisibility=protected

ANDROID_NAME = $(LIB)
ANDROID_BUILDTYPE = lib

# Add library makefile to dependencies for makefile fragment
ANDROID_MK += $(call select_from_repositories,lib/mk/$(LIB).mk)

# Add android build fragments to rebuild android.mk when build files change
ANDROID_MK += $(call select_from_repositories,lib/mk/android-lib.inc)
ANDROID_MK += $(call select_from_repositories,lib/mk/android.inc)

include $(call select_from_repositories,lib/mk/android.inc)
SHARED_LIB  = yes

# Include import file of the current library to make definitions available
include $(call select_from_repositories,lib/import/import-$(ANDROID_NAME).mk)

TARGET = dalvikvm
SRC_CC = dalvikvm.cc

DALVIKVM_DIR := $(call select_from_ports,dalvikvm)/art/dalvikvm
vpath %.cc $(DALVIKVM_DIR)

LIBS += libnativehelper liblog stdcxx
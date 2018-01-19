include $(REP_DIR)/lib/import/import-cxxthreads.mk

SHARED_LIB = yes

SRC_CC = cxxthreads.cc
LIBS += stdcxx base

vpath %.cc $(REP_DIR)/src/lib/cxxthreads

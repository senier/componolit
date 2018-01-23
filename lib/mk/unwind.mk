vpath % $(call select_from_repositories,src/lib/unwind)

SRC_C += main.c
SHARED_LIB = yes
CC_CXX_WARN_STRICT =

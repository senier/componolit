CORE_DIR   := $(call select_from_ports,liblog)/system/core
LIBLOG_DIR := $(CORE_DIR)/liblog

SRC_C = log_event_list.c log_event_write.c logger_write.c config_write.c \
		config_read.c logger_name.c logger_lock.c fake_log_device.c fake_writer.c \
		local_logger.c

SRC_CC = log_ratelimit.cpp 

CC_OPT  += -DFAKE_LOG_DEVICE="1"
CPP_OPT += $(CC_OPT)

vpath % $(LIBLOG_DIR)

INC_DIR += $(CORE_DIR)/include
INC_DIR += $(LIBLOG_DIR)
INC_DIR += $(LIBLOG_DIR)/include

LIBS += libc cxx
SHARED_LIB  = yes

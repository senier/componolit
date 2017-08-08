VALGRIND_DIR = $(call select_from_ports,valgrind)/valgrind

INC_DIR += $(VALGRIND_DIR) $(VALGRIND_DIR)/include

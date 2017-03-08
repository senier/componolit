LIBART_DIR := $(call select_from_ports,libart)/art/runtime

SRC_CC = \
	art_field.cc \
	art_method.cc \
	atomic.cc \
	barrier.cc \
	base/allocator.cc \
	base/arena_allocator.cc \
	base/arena_bit_vector.cc \
	base/bit_vector.cc \
	base/file_magic.cc \
	base/hex_dump.cc \
	base/logging.cc \
	base/mutex.cc \
	base/scoped_arena_allocator.cc \
	base/scoped_flock.cc \
	base/stringpiece.cc \
	base/time_utils.cc \
	base/timing_logger.cc \
	base/unix_file/fd_file.cc \
	base/unix_file/random_access_file_utils.cc \
	cha.cc \
	check_jni.cc \
	class_linker.cc \
	class_table.cc \
	code_simulator_container.cc \
	common_throws.cc \
	compiler_filter.cc \
	debugger.cc \
	dex_file.cc \
	dex_file_annotations.cc \
	dex_file_verifier.cc \
	dex_instruction.cc \
	elf_file.cc \
	exec_utils.cc \
	fault_handler.cc \
	gc/allocation_record.cc \
	gc/allocator/dlmalloc.cc \
	gc/allocator/rosalloc.cc \
	gc/accounting/bitmap.cc \
	gc/accounting/card_table.cc \
	gc/accounting/heap_bitmap.cc \
	gc/accounting/mod_union_table.cc \
	gc/accounting/remembered_set.cc \
	gc/accounting/space_bitmap.cc \
	gc/collector/concurrent_copying.cc \
	gc/collector/garbage_collector.cc \
	gc/collector/immune_region.cc \
	gc/collector/immune_spaces.cc \
	gc/collector/mark_compact.cc \
	gc/collector/mark_sweep.cc \
	gc/collector/partial_mark_sweep.cc \
	gc/collector/semi_space.cc \
	gc/collector/sticky_mark_sweep.cc \
	gc/gc_cause.cc \
	gc/heap.cc \
	gc/reference_processor.cc \
	gc/reference_queue.cc \
	gc/scoped_gc_critical_section.cc \
	gc/space/bump_pointer_space.cc \
	gc/space/dlmalloc_space.cc \
	gc/space/image_space.cc \
	gc/space/large_object_space.cc \
	gc/space/malloc_space.cc \
	gc/space/region_space.cc \
	gc/space/rosalloc_space.cc \
	gc/space/space.cc \
	gc/space/zygote_space.cc \
	gc/task_processor.cc \
	hprof/hprof.cc \
	image.cc \
	indirect_reference_table.cc \
	instrumentation.cc \
	intern_table.cc \
	interpreter/interpreter.cc \
	interpreter/interpreter_common.cc \
	interpreter/interpreter_switch_impl.cc \
	interpreter/unstarted_runtime.cc \
	java_vm_ext.cc \
	jdwp/jdwp_event.cc \
	jdwp/jdwp_expand_buf.cc \
	jdwp/jdwp_handler.cc \
	jdwp/jdwp_main.cc \
	jdwp/jdwp_request.cc \
	jdwp/jdwp_socket.cc \
	jdwp/object_registry.cc \
	jni_env_ext.cc \
	jit/debugger_interface.cc \
	jit/jit.cc \
	jit/jit_code_cache.cc \
	jit/profile_compilation_info.cc \
	jit/profiling_info.cc \
	jit/profile_saver.cc \
	jni_internal.cc \
	jobject_comparator.cc \
	linear_alloc.cc \
	mem_map.cc \
	memory_region.cc \
	method_handles.cc \
	mirror/array.cc \
	mirror/call_site.cc \
	mirror/class.cc \
	mirror/class_ext.cc \
	mirror/dex_cache.cc \
	mirror/emulated_stack_frame.cc \
	mirror/executable.cc \
	mirror/field.cc \
	mirror/method.cc \
	mirror/method_handle_impl.cc \
	mirror/method_handles_lookup.cc \
	mirror/method_type.cc \
	mirror/object.cc \
	mirror/reference.cc \
	mirror/stack_trace_element.cc \
	mirror/string.cc \
	mirror/throwable.cc \
	monitor.cc \
	native_bridge_art_interface.cc \
	native_stack_dump.cc \
	native/dalvik_system_DexFile.cc \
	native/dalvik_system_VMDebug.cc \
	native/dalvik_system_VMRuntime.cc \
	native/dalvik_system_VMStack.cc \
	native/dalvik_system_ZygoteHooks.cc \
	native/java_lang_Class.cc \
	native/java_lang_DexCache.cc \
	native/java_lang_Object.cc \
	native/java_lang_String.cc \
	native/java_lang_StringFactory.cc \
	native/java_lang_System.cc \
	native/java_lang_Thread.cc \
	native/java_lang_Throwable.cc \
	native/java_lang_VMClassLoader.cc \
	native/java_lang_Void.cc \
	native/java_lang_invoke_MethodHandleImpl.cc \
	native/java_lang_ref_FinalizerReference.cc \
	native/java_lang_ref_Reference.cc \
	native/java_lang_reflect_Array.cc \
	native/java_lang_reflect_Constructor.cc \
	native/java_lang_reflect_Executable.cc \
	native/java_lang_reflect_Field.cc \
	native/java_lang_reflect_Method.cc \
	native/java_lang_reflect_Parameter.cc \
	native/java_lang_reflect_Proxy.cc \
	native/java_util_concurrent_atomic_AtomicLong.cc \
	native/libcore_util_CharsetUtils.cc \
	native/org_apache_harmony_dalvik_ddmc_DdmServer.cc \
	native/org_apache_harmony_dalvik_ddmc_DdmVmInternal.cc \
	native/sun_misc_Unsafe.cc \
	non_debuggable_classes.cc \
	oat.cc \
	oat_file.cc \
	oat_file_assistant.cc \
	oat_file_manager.cc \
	oat_quick_method_header.cc \
	object_lock.cc \
	offsets.cc \
	os_linux.cc \
	parsed_options.cc \
	plugin.cc \
	primitive.cc \
	quick_exception_handler.cc \
	quick/inline_method_analyser.cc \
	reference_table.cc \
	reflection.cc \
	runtime.cc \
	runtime_callbacks.cc \
	runtime_common.cc \
	runtime_options.cc \
	signal_catcher.cc \
	stack.cc \
	stack_map.cc \
	thread.cc \
	thread_list.cc \
	thread_pool.cc \
	ti/agent.cc \
	trace.cc \
	transaction.cc \
	type_lookup_table.cc \
	utf.cc \
	utils.cc \
	vdex_file.cc \
	verifier/instruction_flags.cc \
	verifier/method_verifier.cc \
	verifier/reg_type.cc \
	verifier/reg_type_cache.cc \
	verifier/register_line.cc \
	verifier/verifier_deps.cc \
	verify_object.cc \
	well_known_classes.cc \
	zip_archive.cc \
	arch/context.cc \
	arch/instruction_set.cc \
	arch/instruction_set_features.cc \
	arch/memcmp16.cc \
	arch/arm/instruction_set_features_arm.cc \
	arch/arm/registers_arm.cc \
	arch/arm64/instruction_set_features_arm64.cc \
	arch/arm64/registers_arm64.cc \
	arch/mips/instruction_set_features_mips.cc \
	arch/mips/registers_mips.cc \
	arch/mips64/instruction_set_features_mips64.cc \
	arch/mips64/registers_mips64.cc \
	arch/x86/instruction_set_features_x86.cc \
	arch/x86/registers_x86.cc \
	arch/x86_64/registers_x86_64.cc \
	entrypoints/entrypoint_utils.cc \
	entrypoints/jni/jni_entrypoints.cc \
	entrypoints/math_entrypoints.cc \
	entrypoints/quick/quick_alloc_entrypoints.cc \
	entrypoints/quick/quick_cast_entrypoints.cc \
	entrypoints/quick/quick_deoptimization_entrypoints.cc \
	entrypoints/quick/quick_dexcache_entrypoints.cc \
	entrypoints/quick/quick_entrypoints_enum.cc \
	entrypoints/quick/quick_field_entrypoints.cc \
	entrypoints/quick/quick_fillarray_entrypoints.cc \
	entrypoints/quick/quick_instrumentation_entrypoints.cc \
	entrypoints/quick/quick_jni_entrypoints.cc \
	entrypoints/quick/quick_lock_entrypoints.cc \
	entrypoints/quick/quick_math_entrypoints.cc \
	entrypoints/quick/quick_thread_entrypoints.cc \
	entrypoints/quick/quick_throw_entrypoints.cc \
	entrypoints/quick/quick_trampoline_entrypoints.cc \

ifeq ($(filter-out $(SPECS),x86_64),)
else
# Note that the fault_handler_x86.cc is not a mistake.  This file is
# shared between the x86 and x86_64 architectures.
SRC_CC += \
	interpreter/mterp/mterp.cc \
	arch/x86_64/context_x86_64.cc \
	arch/x86_64/entrypoints_init_x86_64.cc \
	arch/x86_64/thread_x86_64.cc \
	monitor_pool.cc \
	arch/x86/fault_handler_x86.cc \

SRC_S += \
	interpreter/mterp/out/mterp_x86_64.S \
	arch/x86_64/jni_entrypoints_x86_64.S \
	arch/x86_64/memcmp16_x86_64.S \
	arch/x86_64/quick_entrypoints_x86_64.S \

ifeq ($(filter-out $(SPECS),x86_32),)

SRC_CC += \
	interpreter/mterp/mterp.cc \
	arch/x86/context_x86.cc \
	arch/x86/entrypoints_init_x86.cc \
	arch/x86/thread_x86.cc \
	arch/x86/fault_handler_x86.cc

SRC_S += \
	interpreter/mterp/out/mterp_x86.S \
	arch/x86/jni_entrypoints_x86.S \
	arch/x86/memcmp16_x86.S \
	arch/x86/quick_entrypoints_x86.S \

else
ifeq ($(filter-out $(SPECS),arm),)

SRC_CC += \
	interpreter/mterp/mterp.cc \
	arch/arm/context_arm.cc \
	arch/arm/entrypoints_init_arm.cc \
	arch/arm/quick_entrypoints_cc_arm.cc \
	arch/arm/thread_arm.cc \
	arch/arm/fault_handler_arm.cc \

SRC_S += \
	interpreter/mterp/out/mterp_arm.S \
	arch/arm/instruction_set_features_assembly_tests.S \
	arch/arm/jni_entrypoints_arm.S \
	arch/arm/memcmp16_arm.S \
	arch/arm/quick_entrypoints_arm.S \

else
ifeq ($(filter-out $(SPECS),arm64),)
# No ARM64 support on Genode right now. We still keep the required source
# around for future use.
#
SRC_CC +=
	interpreter/mterp/mterp.cc \
	arch/arm64/context_arm64.cc \
	arch/arm64/entrypoints_init_arm64.cc \
	arch/arm64/thread_arm64.cc \
	monitor_pool.cc \
	arch/arm64/fault_handler_arm64.cc \

SRC_S +=
	interpreter/mterp/out/mterp_arm64.S \
	arch/arm64/jni_entrypoints_arm64.S \
	arch/arm64/memcmp16_arm64.S \
	arch/arm64/quick_entrypoints_arm64.S \

endif
endif
endif
endif

# Host-target specific sources
SRC_CC += \
	monitor_linux.cc \
	runtime_linux.cc \
	thread_linux.cc \

CC_OPT  += -DBUILDING_LIBART="1"
CPP_OPT += $(CC_OPT)

vpath % $(LIBART_DIR)

LIBS += \
	libc \
	cxx \
	zlib \
	libziparchive \
	libnativehelper \
	libnativebridge \
	libnativeloader \
	libbacktrace \
	liblz4 \
	liblog \
	libcutils \
	libbase \
	libsigchain \

# FIXME: Generate operator_out.cc

SHARED_LIB  = yes

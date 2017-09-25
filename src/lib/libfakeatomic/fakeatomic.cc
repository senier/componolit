// Genode includes
#include <base/log.h>

// stdcxx includes
#include <atomic>

// libc includes
#undef ATOMIC_VAR_INIT
#include <stdatomic.h>

namespace std {

void __atomic_thread_fence (memory_order mo __attribute__((unused)))
{
	Genode::warning(__func__, " not implemented");
};

void __atomic_signal_fence (memory_order mo __attribute__((unused)))
{
	Genode::warning(__func__, " not implemented");
};

}

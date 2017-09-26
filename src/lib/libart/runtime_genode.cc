#include "runtime.h"
#include "runtime_common.h"

#include <base/log.h>

namespace art {

void HandleUnexpectedSignalGenode(int signal_number, siginfo_t* info, void* raw_context) {
	Genode::warning(__func__, " not implemented");
}

void Runtime::InitPlatformSignalHandlers() {
	Genode::warning(__func__, " not implemented");
}

}

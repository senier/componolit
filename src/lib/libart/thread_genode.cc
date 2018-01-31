#include <base/log.h>

#include "thread.h"

namespace art {

void Thread::SetUpAlternateSignalStack() {
	Genode::log("SetUpAlternateSignalStack(): Not implemented");
}
void Thread::TearDownAlternateSignalStack() {
	Genode::log("TearDownAlternateSignalStack(): Not implemented ");
}

void Thread::SetNativePriority(int) {
	// Do nothing.
}

int Thread::GetNativePriority() {                                                                                                              
  return kNormThreadPriority;
}

}

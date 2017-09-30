/* Genode includes */
#include <libc/component.h>
#include <os/backtrace.h>

/* libc includes */
#include <stdlib.h> /* 'exit'   */

void sub3()
{
	Genode::log (__FUNCTION__, " called");
	Genode::backtrace();
}

void sub2()
{
	Genode::log (__FUNCTION__, " called");
	sub3();
	Genode::log (__FUNCTION__, " finished");
}

void sub1()
{
	Genode::log (__FUNCTION__, " called");
	sub2();
	Genode::log (__FUNCTION__, " finished");
}

void Libc::Component::construct(Libc::Env &env)
{
	Libc::with_libc([&] {
		Genode::log ("Started");
		sub1();
		exit(0);
	});
}

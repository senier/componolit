/* Genode includes */
#include <libc/component.h>

/* libc includes */
#include <stdlib.h> /* 'exit'   */
#include <string.h>

extern int          genode_argc;
extern const char **genode_argv;

/* provided by the application */
extern "C" void FUZ_unitTests(void);

Genode::size_t Libc::Component::stack_size() {
	return 500*1024;
}

void Libc::Component::construct(Libc::Env &env)
{
	Libc::with_libc([&env] {

		char const *argv[] = {
			"/bin/test_liblz4",
			0
		};

		genode_argc = 1;
		genode_argv = argv;

		setprogname (genode_argv[0]);
		FUZ_unitTests();
		exit(0);
	});
}

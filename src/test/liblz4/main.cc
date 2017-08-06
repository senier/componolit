/* Genode includes */
#include <libc/component.h>

/* libc includes */
#include <stdlib.h> /* 'exit'   */
#include <string.h>

extern int          genode_argc;
extern const char **genode_argv;

/* provided by the application */
extern "C" int main(int argc, char const **argv);

Genode::size_t Libc::Component::stack_size() {
	return 500*1024;
}

void Libc::Component::construct(Libc::Env &env)
{
	Libc::with_libc([&] {

		char const *argv[] = {
			"/bin/test_liblz4",
			"-i1",
			"-v",
			0
		};

		genode_argc = 3;
		genode_argv = argv;

		setprogname (genode_argv[0]);
		exit(main(genode_argc, genode_argv));
	});
}

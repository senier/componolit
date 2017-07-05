/* Genode includes */
#include <libc/component.h>

/* libc includes */
#include <stdlib.h> /* 'exit'   */

extern int          genode_argc;
extern char const **genode_argv;

/* provided by the application */
extern "C" int main(int argc, char const **argv);

void Libc::Component::construct(Libc::Env &env)
{
	Libc::with_libc([&] {

		char const *argv[] = {
			"/bin/test_libbase",
			"--gtest_filter=-logging.LOG_STREAM_FATAL_WITHOUT_ABORT_*:logging.LOG_STREAM_*:logging.LOG_FATAL_WITHOUT_ABORT_*:logging.LOG_*_*:logging.LOG_complex_param:logging.*LOG_does_not_clobber_errno:logging.LOG_does_not_have_dangling_if:logging.PLOG_FATAL_WITHOUT_ABORT_*:logging.PLOG_*_*:logging.UNIMPLEMENTED",
			0
		};

		genode_argc = 2;
		genode_argv = argv;

		setprogname (genode_argv[0]);
		exit (main(genode_argc, genode_argv));
	});
}

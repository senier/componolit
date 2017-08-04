/* Genode includes */
#include <libc/component.h>

/* libc includes */
#include <stdlib.h> /* 'exit'   */
#include <stdio.h>
#include <unistd.h>
#include <err.h>

/* stdcxx includes */
#include <string>

// nanosleep seems to ignore nanoseconds.
// Sometimes there is a suspicious warning when running the test:
// Warning: submitting signal failed - error 4 - context=cap<34548>

void Libc::Component::construct(Libc::Env &env)
{
	Libc::with_libc([&] {

		time_t last = time(nullptr);

	 	struct timespec duration;	
		duration.tv_sec = 1;
		duration.tv_nsec = 500000000;
		nanosleep(&duration, NULL);

		double delta = difftime(time(NULL), last);
		if (delta < 1.5)
		{
			Genode::log("Invalid time diff: ", delta);
			exit (1);
		}

		exit (0);
	});
}

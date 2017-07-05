/* Genode includes */
#include <libc/component.h>

/* libc includes */
#include <stdlib.h> /* 'exit'   */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <err.h>

void Libc::Component::construct(Libc::Env &env)
{
	Libc::with_libc([&] {

		unlink ("/tmp/nonexistent");

    	char *result = realpath ("/tmp/nonexistent/", NULL);
    	if (result == NULL)
    	{
			Genode::log ("OK");
			exit (0);
    	}

		Genode::log ("Invalid path did not return NULL");
		exit (1);
	});
}

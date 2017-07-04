/* Genode includes */
#include <libc/component.h>

/* libc includes */
#include <stdlib.h> /* 'exit'   */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <err.h>
#include <string.h>

void Libc::Component::construct(Libc::Env &env)
{
	Libc::with_libc([&] {

		const char *data = "data";
		char buf[4096];

		int error = 0;
		int rv = symlink (data, "/tmp/symlink");
		if (rv < 0) err (2, "symlink");

		ssize_t len = readlink("/tmp/symlink", buf, sizeof (buf));
		if (len < 0) err (3, "readlink symlink");

		if (buf[len-1] == '\0')
		{
			Genode::error ("readlink() result is NULL-terminated");
			error = 1;
		}

		if ((size_t)len != strlen (data))
		{
			Genode::error ("Invalid length returned from readlink: expected=", strlen (data), " found=", len);
			error = 2;
		}

		if (strncmp (data, buf, strlen(data)))
		{
			Genode::error ("Result differs");
			error = 3;
		}

		exit (error);
	});
}

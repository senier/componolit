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

		char target[10000], data[sizeof(target)];

		for (unsigned int i = 0; i < sizeof(target); i++)
		{
			memset (target, i % 255 + 1, i);
			target[i] = '\0';

			int rv = symlink (target, "/tmp/symlink");
			if (rv < 0) err (2, "symlink (@%d bytes)", i);

			ssize_t len = readlink("/tmp/symlink", data, sizeof (data));
			if (len < 0) err (3, "readlink symlink");

			if (strncmp (target, data, i))
			{
				Genode::error ("Result differs at ", i);
				exit (3);
			}

			unlink ("/tmp/symlink");
		}
	});
}

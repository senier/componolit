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

		int fd = open ("/tmp/file", O_CREAT | O_NOFOLLOW, 0666);
		if (fd < 0) err (1, "open file");

		int rv = symlink ("/tmp/file", "/tmp/symlink");
		if (rv < 0) err (2, "symlink");

		fd = open("/tmp/symlink", O_NOFOLLOW);
		if (fd < 0) err (3, "open symlink");
	});
}

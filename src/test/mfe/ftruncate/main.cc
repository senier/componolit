/* Genode includes */
#include <libc/component.h>

/* libc includes */
#include <stdlib.h> /* 'exit'   */
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

void Libc::Component::construct(Libc::Env &env)
{
	Libc::with_libc([&] {
		int fd = open ("/tmp/file", O_CREAT, 0666);
		if (fd < 0) exit (1);
		int rv = unlink("/tmp/file");
		if (rv < 0) exit (2);
		rv = ftruncate(fd, 1);
		if (rv < 0) exit (3);
		exit (0);
	});
}

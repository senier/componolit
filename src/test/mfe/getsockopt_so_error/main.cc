/* Genode includes */
#include <libc/component.h>

/* libc includes */
#include <stdlib.h> /* 'exit'   */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <err.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/uio.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/* stdcxx includes */
#include <string>

void Libc::Component::construct(Libc::Env &env)
{
	Libc::with_libc([&] {

		int sendsock = -1;
		int recvsock = -1;
		int rv, flags = -1;
		int error = -1;

		struct sockaddr_in addr;

		memset (&addr, 0, sizeof(addr));
		addr.sin_family = AF_INET;
		addr.sin_port   = htons(10080);
		addr.sin_addr.s_addr = inet_addr("127.0.0.1");

		sendsock = socket(AF_INET, SOCK_STREAM, 0);
		if (sendsock < 0) err (1, "recv socket");

		int enable = 1;
		if (setsockopt(sendsock, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0) err (1, "setsockopt(SO_REUSEADDR) failed");

		if (bind(sendsock, (struct sockaddr *) &addr, sizeof(addr)) < 0) err(2, "bind");

		rv = listen(sendsock, 3);
		if (rv < 0) err(3, "listen");

		recvsock = socket(AF_INET, SOCK_STREAM, 0);
		if (recvsock < 0) err (4, "send socket");

		if (flags = fcntl(recvsock, F_GETFL) < 0) err(1, "F_GETFL");
		if (fcntl(recvsock, F_SETFL, flags | O_NONBLOCK) < 0) err(1, "F_SETFL");

		rv = connect(recvsock, (struct sockaddr *)&addr, sizeof(addr));
		if (rv < 0 && errno != EINPROGRESS) err(5, "connect");

        fd_set r_set;
        FD_ZERO(&r_set);
        FD_SET(recvsock, &r_set);
        fd_set w_set = r_set;

        if ((rv = select(recvsock + 1, &r_set, &w_set, NULL, NULL)) < 0) err(1, "select");

        if (FD_ISSET(recvsock, &r_set) || FD_ISSET(recvsock, &w_set)) {
			socklen_t len = sizeof(error);
            if (getsockopt(recvsock, SOL_SOCKET, SO_ERROR, &error, &len) < 0) err(1, "getsockopt(SO_ERROR)");
			printf ("error: %d (%s)\n", error, strerror(error));
		}

		exit (error);
	});
}

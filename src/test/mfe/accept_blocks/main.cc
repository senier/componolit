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

// FIXME: This does not reproduce the error in libcutils.SocketTest.TestTcpReceiveTimeout

void Libc::Component::construct(Libc::Env &env)
{
	Libc::with_libc([&] {

		int sendsock  = -1;
		int recvsock  = -1;
		int rv, flags = -1;

		enum { NUM_ELEMS = 3 };

		// Server
		struct sockaddr_in saddr;
		memset (&saddr, 0, sizeof(saddr));
		saddr.sin_family = AF_INET;
		saddr.sin_port   = htons(10080);
		saddr.sin_addr.s_addr = htonl(INADDR_ANY);
		
		if ((recvsock = socket(AF_INET, SOCK_STREAM, 0)) < 0) err (1, "recv socket");

		int enable = 1;
		if (setsockopt(recvsock, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0) err (1, "setsockopt(SO_REUSEADDR) failed");

		if (bind(recvsock, (struct sockaddr *) &saddr, sizeof(saddr)) < 0) err(2, "bind");

		rv = listen(recvsock, 4);
		if (rv < 0) err(3, "listen");

		// Client
		struct sockaddr_in caddr;
		memset (&caddr, 0, sizeof(caddr));
		caddr.sin_family = AF_INET;
		caddr.sin_port   = htons(10080);
		caddr.sin_addr.s_addr = inet_addr("127.0.0.1");

		sendsock = socket(AF_INET, SOCK_STREAM, 0);
		if (sendsock < 0) err (4, "send socket");

		if ((flags = fcntl(sendsock, F_GETFL)) < 0) err(1, "F_GETFL");
		if (fcntl(sendsock, F_SETFL, flags ^ O_NONBLOCK) < 0) err(1, "F_SETFL 1");

		rv = connect(sendsock, (struct sockaddr *)&caddr, sizeof(caddr));
		if (rv < 0 && errno != EINPROGRESS) err(5, "connect");

		if (rv != 0)
		{
        	fd_set r_set;
        	FD_ZERO(&r_set);
        	FD_SET(sendsock, &r_set);
        	fd_set w_set = r_set;

        	if ((rv = select(sendsock + 1, &r_set, &w_set, NULL, NULL)) < 0) err(1, "select");
		}

		if ((flags = fcntl(sendsock, F_GETFL)) < 0) err(1, "F_GETFL");
		if (fcntl(sendsock, F_SETFL, flags ^ O_NONBLOCK) < 0) err(1, "F_SETFL 2");

		// Server: accept connection
		int conn = accept(recvsock, nullptr, nullptr);
		if (conn < 0) err (7, "accept");

		exit (0);
	});
}

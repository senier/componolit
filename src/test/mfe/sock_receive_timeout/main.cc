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

		int sock = -1;
		int rv = -1;
		struct sockaddr_in addr;
		timeval tv;
		char buf[32];

		// Increase to 1000 and the issue vanishes.
		enum { TIMEOUT_MS = 999 };

		memset (&addr, 0, sizeof(addr));
		addr.sin_family = AF_INET;
		addr.sin_port   = htons(10080);
		addr.sin_addr.s_addr = htonl(INADDR_ANY);

		if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) err (1, "recv socket");

		int enable = 1;
		if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0) err (1, "setsockopt(...SO_REUSEADDR...)");

		if (bind(sock, (struct sockaddr *) &addr, sizeof(addr)) < 0) err(2, "bind");

		tv.tv_sec = TIMEOUT_MS / 1000;
		tv.tv_usec = (TIMEOUT_MS % 1000) * 1000;
		if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) err(3, "setsockopt(...SO_RCVTIMEO...)");

		if (recv(sock, buf, sizeof(buf), 0) < 0) err(4, "recv: %d", errno);

		exit (0);
	});
}

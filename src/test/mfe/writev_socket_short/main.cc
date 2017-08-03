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
		ssize_t len  = -1;
		int rv		 = -1;

		enum { NUM_ELEMS = 3 };

		struct sockaddr_in addr;
		iovec bufs[NUM_ELEMS];
		char buf[18];

   		std::string data[] = {"data", "data2", "datadata"};

		for (size_t i = 0; i < NUM_ELEMS; ++i) {
			bufs[i].iov_base = const_cast<char *>(data[i].c_str());
			bufs[i].iov_len  = data[i].length();
		}

		memset (&addr, 0, sizeof(addr));
		addr.sin_family = AF_INET;
		addr.sin_port   = htons(10080);
		addr.sin_addr.s_addr = inet_addr("127.0.0.1");

		recvsock = socket(AF_INET, SOCK_STREAM, 0);
		if (recvsock < 0) err (1, "recv socket");

		int enable = 1;
		if (setsockopt(recvsock, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0) err (1, "setsockopt(SO_REUSEADDR) failed");

		if (bind(recvsock, (struct sockaddr *) &addr, sizeof(addr)) < 0) err(2, "bind");

		rv = listen(recvsock, 3);
		if (rv < 0) err(3, "listen");

		sendsock = socket(AF_INET, SOCK_STREAM, 0);
		if (sendsock < 0) err (4, "send socket");

		rv = connect(sendsock, (struct sockaddr *)&addr, sizeof(addr));
		if (rv < 0) err(5, "connect");

		len = writev(sendsock, bufs, NUM_ELEMS);
		if (len < 0) err(6, "writev");

		printf ("writev: Transferred %d bytes\n", len);

		int conn = accept(recvsock, NULL, 0);
		if (conn < 0) err (7, "accept");

		len = recv(conn, buf, sizeof(buf), 0);
		if (len < 0) err(8, "recv");
		if (len != 17) {
			errx(9, "recv invalid length (got %d, expected %d, content=%s)", len, 17, buf);
		}

		if (memcmp(buf, "datadata2datadata", 17) != 0) errx(10, "memcmp");

		exit (0);
	});
}

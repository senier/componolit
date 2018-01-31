/*                                                                                                                                             
 * Copyright (C) 2015 The Android Open Source Project
 * Copyright (C) 2018 Componolit GmbH
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* Genode includes */
#include <libc/component.h>

/* libc includes */
#include <stdlib.h> /* 'exit'   */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <err.h>
#include <errno.h>
#include <string.h>

// bionic and glibc both have TEMP_FAILURE_RETRY, but eg Mac OS' libc doesn't.
#ifndef TEMP_FAILURE_RETRY
#define TEMP_FAILURE_RETRY(exp)            \
  ({                                       \
    decltype(exp) _rc;                     \
    do {                                   \
      _rc = (exp);                         \
    } while (_rc == -1 && errno == EINTR); \
    _rc;                                   \
  })
#endif

bool WriteFully (int fd, const void* data, size_t byte_count) {
  const uint8_t* p = reinterpret_cast<const uint8_t*>(data);
  size_t remaining = byte_count;
  while (remaining > 0) {
    ssize_t n = TEMP_FAILURE_RETRY(write(fd, p, remaining));
    if (n == -1) return false;
    p += n;
    remaining -= n;
  }
  return true;
}

#define DATA_SIZE 100
#define NUM_RUNS 1000
#define TMPFILE "/tmp/tmpfile"
char data[DATA_SIZE];

char path[1024];

int write_file()
{
    int fd;

    // Create temp file
    fd = open(TMPFILE, O_CREAT|O_TRUNC|O_RDWR);
    if (fd < 0) err(1, "mkstemp");

    // Write buffer to file
    if (!WriteFully(fd, data, sizeof(data))) errx(2, "WriteFully");

    // Uncomment to fix the issue
    //fsync(fd);

    // Check whether end of file equals data size
    off_t len = lseek (fd, 0, SEEK_END); 
    close (fd);
    unlink(TMPFILE);

    return len == DATA_SIZE;
}

void Libc::Component::construct(Libc::Env &env)
{
	Libc::with_libc([&] {

        int ok = 0;
        int fail = 0;

        memset (data, 'x', sizeof(data));

        Genode::warning ("Test stated with ", NUM_RUNS, " runs");

        for (int i = 0; i < NUM_RUNS; i++)
        {
            if (write_file())
            {
                ok++;
            } else {
                fail++;
            }
        }

        Genode::warning ("Failed: ", fail, " OK: ", ok);

        if (fail) exit (1);
        exit (0);

	});
}

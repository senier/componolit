/*
 * \brief Debug function to log into memory
 * \author Alexander Senier
 * \date 2018-01-15
 *
 * USE FOR DEBUGGING ONLY!
 *
 * This is meant for situations where logging is not yet available, but
 * the target can be made run on Qemu. Include this file and insert
 * memlog() statements into your code as necessary.
 *
 * Once your program emmited the desired log messages, change to the
 * Qemu console and dump system memory to a file:
 *
 * (qemu) dump-guest-memory out.dump
 * (qemu) quit
 *
 * Extract the logs as follows:
 * 
 * $ sed -ne 's/STARTLOG:\(.*\):ENDLOG/\1/p' out.dump
 *
 * Happy debugging!
 */

/*
 * Copyright (C) 2018 Componolit GmbH
 *
 * This file is part of the Componolit platform, which is distributed
 * under the terms of the GNU Affero General Public License version 3.
 */


#pragma once
#warning "Unsafe code, use for debugging only"

enum { MEMLOG_BUFFER_LENGTH = 4096, };

static char memlogbuffer[MEMLOG_BUFFER_LENGTH] __attribute__((used)) = "\n";
static unsigned memlogposition = 1;

static void memlog(const char message[])
{
    // set start tag manually to prevent 'STARTLOG:' constant to be found by sed
    memlogbuffer[memlogposition++] = 'S';
    memlogbuffer[memlogposition++] = 'T';
    memlogbuffer[memlogposition++] = 'A';
    memlogbuffer[memlogposition++] = 'R';
    memlogbuffer[memlogposition++] = 'T';
    memlogbuffer[memlogposition++] = 'L';
    memlogbuffer[memlogposition++] = 'O';
    memlogbuffer[memlogposition++] = 'G';
    memlogbuffer[memlogposition++] = ':';

    do
    {
        memlogbuffer[memlogposition++] = *message++;
    } while (*message);

    // set end tag manually to prevent ':ENDLOG' constant to be found by sed
    memlogbuffer[memlogposition++] = ':';
    memlogbuffer[memlogposition++] = 'E';
    memlogbuffer[memlogposition++] = 'N';
    memlogbuffer[memlogposition++] = 'D';
    memlogbuffer[memlogposition++] = 'L';
    memlogbuffer[memlogposition++] = 'O';
    memlogbuffer[memlogposition++] = 'G';
    memlogbuffer[memlogposition++] = '\n';
    memlogbuffer[memlogposition++] = 0;
};

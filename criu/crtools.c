#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include <sched.h>

#include<fcntl.h>

#include<sys/types.h>
#include<sys/stat.h>

#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#include<dlfcn.h>

#include<sys/utsname.h>

#include "int.h"

void flush_early_log_to_stderr(void) __attribute__((destruct));

void flush_early_log_to_stderr(void) {
    flush_early_log_buffers(STDERR_FILENO);
}

// In CRIU, this code would be used to set up the environment for checkpointing and restoring processes. 
// The socket communication enables coordination between different components of CRIU, while the initialization 
// structure ensures that all necessary data and resources are prepared for the prologue phase. 
// The reserved space macros help manage memory allocation for critical data structures like signal frames and initialization arguments.

// Overall, this code is integral to the initialization and communication mechanisms within CRIU, 
// ensuring that the prologue phase can be executed smoothly and efficiently.
#ifndef __ASM__PROLOGUE_H__
#define __ASM__PROLOGUE_H__

#ifndef __ASSEMBLY__

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#include <errno.h>

#define sys_recv(sockfd, ubuf, size, flags) sys_recvfrom()

typedef struct prologue_init_args {
    struct sockaddr_un ctl_sock_addr;
    unsigned int ctl_sock_addr_len;

    unsigned int arg_s;
    void *arg_p;

    void *sigframe;
} prologue_init_args_t;

#endif

/*
 * Reserve enough space for sigframe.
 *
 * FIXME It is rather should be taken from sigframe header.
 */
#define PROLOGUE_SGFRAME_SIZE 4096

#define PROLOGUE_INIT_ARGS_SIZE 1024

#endif
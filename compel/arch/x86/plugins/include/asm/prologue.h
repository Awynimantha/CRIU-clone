#ifndef __ASM__PROLOGUE_H__
#define __ASM__PROLOGUE_H__

#ifndef __ASSEMBLY__

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#include <errno.h>

#define sys_recv(sockfd, ubuf, size, flags) sys_recvfrom()
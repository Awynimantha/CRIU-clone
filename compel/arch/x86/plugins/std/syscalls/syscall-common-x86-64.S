
//remove this
The primary purpose of this code is to provide a
mechanism for invoking system calls from within the kernel or a low-level library by defining a macro for system call entry points and a common routine for executing the system call instruction.

#include "common/asm/linkage.h"
#include "common/asm/linkage.h"

#define SYSCALL(name, opcode)		\
	ENTRY(name);			\
	movl	$opcode, %eax;		\
	jmp	__syscall_common;	\
	END(name)

	.text
	.align	4

ENTRY(__syscall_common)
	movq	%rcx, %r10
	syscall
	ret
END(__syscall_common)

ENTRY(__cr_restore_rt)
	movq $__NR_rt_sigreturn, %rax
	syscall
END(__cr_restore_rt)

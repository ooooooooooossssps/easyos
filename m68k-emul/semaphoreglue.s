#include "machine.i"

/*
    The following functions are guaranteed to preserve
    all registers. But I don't want to write them completely
    in assembly - C is generally more readable.
    So I use those stubs to preserve the registers.
*/

	.text
	.balign 16
	.globl	easyos_SLIB_ENTRY(_ObtainSemaphore,Exec)
	.type	easyos_SLIB_ENTRY(_ObtainSemaphore,Exec),@function
easyos_SLIB_ENTRY(_ObtainSemaphore,Exec):
	movem.l	%d0-%d1/%a0-%a1,-(%sp)
	move.l	24(%sp),-(%sp)
	move.l	24(%sp),-(%sp)
	bsr.l	easyos_SLIB_ENTRY(ObtainSemaphore,Exec)
	addq.w	#8,%sp
	movem.l	(%sp)+,%d0-%d1/%a0-%a1
	rts

	.globl	easyos_SLIB_ENTRY(_ReleaseSemaphore,Exec)
	.type	easyos_SLIB_ENTRY(_ReleaseSemaphore,Exec),@function
easyos_SLIB_ENTRY(_ReleaseSemaphore,Exec):
	movem.l	%d0-%d1/%a0-%a1,-(%sp)
	move.l	24(%sp),-(%sp)
	move.l	24(%sp),-(%sp)
	bsr.l	easyos_SLIB_ENTRY(ReleaseSemaphore,Exec)
	addq.w	#8,%sp
	movem.l	(%sp)+,%d0-%d1/%a0-%a1
	rts

	.globl	easyos_SLIB_ENTRY(_ObtainSemaphoreShared,Exec)
	.type	easyos_SLIB_ENTRY(_ObtainSemaphoreShared,Exec),@function
easyos_SLIB_ENTRY(_ObtainSemaphoreShared,Exec):
	movem.l	%d0-%d1/%a0-%a1,-(%sp)
	move.l	24(%sp),-(%sp)
	move.l	24(%sp),-(%sp)
	bsr.l	easyos_SLIB_ENTRY(ObtainSemaphoreShared,Exec)
	addq.w	#8,%sp
	movem.l	(%sp)+,%d0-%d1/%a0-%a1
	rts

Footer

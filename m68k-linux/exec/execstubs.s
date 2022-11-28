#include "machine.i"

/*
    The following functions are guaranteed to preserve
    all registers. But I don't want to write them completely
    in assembly - C is generally more readable.
    So I use those stubs to preserve the registers.
*/
#ifdef UseExecstubs

	.text
	.balign 16
	.globl	easyos_SLIB_ENTRY(ObtainSemaphore,Exec)
	.type	easyos_SLIB_ENTRY(ObtainSemaphore,Exec),@function
easyos_SLIB_ENTRY(ObtainSemaphore,Exec):
	movem.l	%d0-%d1/%a0-%a1,-(%sp)
	move.l	%a6,-(%sp)
	move.l	%a0,-(%sp)
#ifdef __PIC__
	bsr.l	easyos_CSYMNAME(_Exec_ObtainSemaphore)@PLTPC
#else
	jbsr	easyos_CSYMNAME(_Exec_ObtainSemaphore)
#endif
	addq.w	#8,%sp
	movem.l	(%sp)+,%d0-%d1/%a0-%a1
	rts

	.globl	easyos_SLIB_ENTRY(ReleaseSemaphore,Exec)
	.type	easyos_SLIB_ENTRY(ReleaseSemaphore,Exec),@function
easyos_SLIB_ENTRY(ReleaseSemaphore,Exec):
	movem.l	%d0-%d1/%a0-%a1,-(%sp)
	move.l	%a6,-(%sp)
	move.l	%a0,-(%sp)
#ifdef __PIC__
	bsr.l	easyos_CSYMNAME(_Exec_ReleaseSemaphore)@PLTPC
#else
	jbsr	easyos_CSYMNAME(_Exec_ReleaseSemaphore)
#endif
	addq.w	#8,%sp
	movem.l	(%sp)+,%d0-%d1/%a0-%a1
	rts

	.globl	easyos_SLIB_ENTRY(ObtainSemaphoreShared,Exec)
	.type	easyos_SLIB_ENTRY(ObtainSemaphoreShared,Exec),@function
easyos_SLIB_ENTRY(ObtainSemaphoreShared,Exec):
	movem.l	%d0-%d1/%a0-%a1,-(%sp)
	move.l	%a6,-(%sp)
	move.l	%a0,-(%sp)
#ifdef __PIC__
	bsr.l	easyos_CSYMNAME(_Exec_ObtainSemaphoreShared)@PLTPC
#else
	jbsr	easyos_CSYMNAME(_Exec_ObtainSemaphoreShared)
#endif
	addq.w	#8,%sp
	movem.l	(%sp)+,%d0-%d1/%a0-%a1
	rts

        .globl	easyos_SLIB_ENTRY(Disable,Exec)
        .type	easyos_SLIB_ENTRY(Disable,Exec),@function
easyos_SLIB_ENTRY(Disable,Exec):
	movem.l	%d0-%d1/%a0-%a1,-(%sp)
	move.l	%a6,-(%sp)
#ifdef __PIC__
	bsr.l	easyos_CSYMNAME(_Exec_Disable)@PLTPC
#else
	jbsr	easyos_CSYMNAME(_Exec_Disable)
#endif
	addq.w	#4,%sp
	movem.l	(%sp)+,%d0-%d1/%a0-%a1
	rts

	.globl	easyos_SLIB_ENTRY(Enable,Exec)
	.type	easyos_SLIB_ENTRY(Enable,Exec),@function
easyos_SLIB_ENTRY(Enable,Exec):
	movem.l	%d0-%d1/%a0-%a1,-(%sp)
	move.l	%a6,-(%sp)
#ifdef __PIC__
	bsr.l	easyos_CSYMNAME(_Exec_Enable)@PLTPC
#else
	jbsr	easyos_CSYMNAME(_Exec_Enable)
#endif
	addq.w	#4,%sp
	movem.l	(%sp)+,%d0-%d1/%a0-%a1
	rts

	.globl	easyos_SLIB_ENTRY(Forbid,Exec)
	.type	easyos_SLIB_ENTRY(Forbid,Exec),@function
easyos_SLIB_ENTRY(Forbid,Exec):
	movem.l %d0-%d1/%a0-%a1,-(%sp)
	move.l	%a6,-(%sp)
#ifdef __PIC__
	bsr.l	easyos_CSYMNAME(_Exec_Forbid)@PLTPC
#else
	jbsr	easyos_CSYMNAME(_Exec_Forbid)
#endif
	addq.w	#4,%sp
	movem.l (%sp)+,%d0-%d1/%a0-%a1
	rts

	.globl	easyos_SLIB_ENTRY(Permit,Exec)
	.type	easyos_SLIB_ENTRY(Permit,Exec),@function
easyos_SLIB_ENTRY(Permit,Exec):
	movem.l %d0-%d1/%a0-%a1,-(%sp)
	move.l	%a6,-(%sp)
#ifdef __PIC__
	bsr.l	easyos_CSYMNAME(_Exec_Permit)@PLTPC
#else
	jbsr	easyos_CSYMNAME(_Exec_Permit)
#endif
	addq.w	#4,%sp
	movem.l (%sp)+,%d0-%d1/%a0-%a1
	rts


#endif


/*
    Copyright © 2017-2022, Fayssal Chokri. All rights reserved.
    $Id$
*/

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
	jbra	AmigaSWInitObtainSemaphore
	jbra	easyos_CSYMNAME(_Exec_ObtainSemaphore)	
AmigaSWInitObtainSemaphore:
	movem.l	%d0-%d1/%a0-%a1,-(%sp)
	move.l	%a6,-(%sp)
	move.l	%a0,-(%sp)
	jbsr	easyos_CSYMNAME(_Exec_ObtainSemaphore)
	addq.w	#8,%sp
	movem.l	(%sp)+,%d0-%d1/%a0-%a1
	rts

	.globl	easyos_SLIB_ENTRY(ReleaseSemaphore,Exec)
	.type	easyos_SLIB_ENTRY(ReleaseSemaphore,Exec),@function
easyos_SLIB_ENTRY(ReleaseSemaphore,Exec):
	jbra	AmigaSWInitReleaseSemaphore
	jbra	easyos_CSYMNAME(_Exec_ReleaseSemaphore)	
AmigaSWInitReleaseSemaphore:
	movem.l	%d0-%d1/%a0-%a1,-(%sp)
	move.l	%a6,-(%sp)
	move.l	%a0,-(%sp)
	jbsr	easyos_CSYMNAME(_Exec_ReleaseSemaphore)
	addq.w	#8,%sp
	movem.l	(%sp)+,%d0-%d1/%a0-%a1
	rts

	.globl	easyos_SLIB_ENTRY(ObtainSemaphoreShared,Exec)
	.type	easyos_SLIB_ENTRY(ObtainSemaphoreShared,Exec),@function
easyos_SLIB_ENTRY(ObtainSemaphoreShared,Exec):
	jbra	AmigaSWInitObtainSemaphoreShared
	jbra	easyos_CSYMNAME(_Exec_ObtainSemaphoreShared)	
AmigaSWInitObtainSemaphoreShared:
	movem.l	%d0-%d1/%a0-%a1,-(%sp)
	move.l	%a6,-(%sp)
	move.l	%a0,-(%sp)
	jbsr	easyos_CSYMNAME(_Exec_ObtainSemaphoreShared)
	addq.w	#8,%sp
	movem.l	(%sp)+,%d0-%d1/%a0-%a1
	rts

        .globl	easyos_SLIB_ENTRY(Disable,Exec)
        .type	easyos_SLIB_ENTRY(Disable,Exec),@function
easyos_SLIB_ENTRY(Disable,Exec):
	jbra	AmigaSWInitDisable
	jbra	easyos_CSYMNAME(_Exec_Disable)	
AmigaSWInitDisable:
	movem.l	%d0-%d1/%a0-%a1,-(%sp)
	move.l	%a6,-(%sp)
	jbsr	easyos_CSYMNAME(_Exec_Disable)
	addq.w	#4,%sp
	movem.l	(%sp)+,%d0-%d1/%a0-%a1
	rts

	.globl	easyos_SLIB_ENTRY(Enable,Exec)
	.type	easyos_SLIB_ENTRY(Enable,Exec),@function
easyos_SLIB_ENTRY(Enable,Exec):
	jbra	AmigaSWInitEnable
	jbra	easyos_CSYMNAME(_Exec_Enable)	
AmigaSWInitEnable:
	movem.l	%d0-%d1/%a0-%a1,-(%sp)
	move.l	%a6,-(%sp)
	jbsr	easyos_CSYMNAME(_Exec_Enable)
	addq.w	#4,%sp
	movem.l	(%sp)+,%d0-%d1/%a0-%a1
	rts

	.globl	easyos_SLIB_ENTRY(Forbid,Exec)
	.type	easyos_SLIB_ENTRY(Forbid,Exec),@function
easyos_SLIB_ENTRY(Forbid,Exec):
	jbra	AmigaSWInitForbid
	jbra	easyos_CSYMNAME(_Exec_Forbid)	
AmigaSWInitForbid:
	movem.l %d0-%d1/%a0-%a1,-(%sp)
	move.l	%a6,-(%sp)
	jbsr	easyos_CSYMNAME(_Exec_Forbid)
	addq.w	#4,%sp
	movem.l (%sp)+,%d0-%d1/%a0-%a1
	rts

	.globl	easyos_SLIB_ENTRY(Permit,Exec)
	.type	easyos_SLIB_ENTRY(Permit,Exec),@function
easyos_SLIB_ENTRY(Permit,Exec):
	jbra	AmigaSWInitPermit
	jbra	easyos_CSYMNAME(_Exec_Permit)	
AmigaSWInitPermit:
	movem.l %d0-%d1/%a0-%a1,-(%sp)
	move.l	%a6,-(%sp)
	jbsr	easyos_CSYMNAME(_Exec_Permit)
	addq.w	#4,%sp
	movem.l (%sp)+,%d0-%d1/%a0-%a1
	rts


#endif

	.align 4
	.globl Exec_SuperState
Exec_SuperState:
	mov	ip, sp
	stmfd	sp!, {r4, fp, ip, lr, pc}
	sub	fp, ip, #4

	mov	r4, r0

	mov	r0, #0          // 1st param
	mov	r1, r0          // 2nd param
	move	r2, r4          // SysBase
	mov	lr, pc
	ldr	pc, [r4, #-96]	// call SetSR

	// check whether I am already in superstate?

	// I am already in superstate!
	ldmea	fp, {r4, fp, sp, pc}

goon:	

	.align 4
	.globl _sys_SuperState
_sys_SuperState:

	#include "../include/easyos/machine.i"

	.text
	.balign 4
	.globl	easyos_SLIB_ENTRY(Supervisor,Exec)

easyos_SLIB_ENTRY(Supervisor,Exec):
	// userFunction parameter is in r0
	// execbase is in r1
	stmdb	sp!,{r4, lr}
	mov	r4,r0
	swi	#8         // #8 => call software interrupt handler
	ldmdb	sp!,{r4, lr}
	mov	pc, lr

	.globl _sys_trap_Supervisor
_sys_trap_Supervisor:
	strdb	sp!,{lr}
	mov	lr, pc      // should add 4 to lr here?
	mov	pc, r4
	ldmdb	sp!,{lr}
	mov	pc, lr

	

	#include "machine.i"

	/* Never Called */
	.text
	.balign 16
	.globl	easyos_SLIB_ENTRY(TrapHandler,Exec)
	.type	easyos_SLIB_ENTRY(TrapHandler,Exec),@function
easyos_SLIB_ENTRY(TrapHandler,Exec):
	rts


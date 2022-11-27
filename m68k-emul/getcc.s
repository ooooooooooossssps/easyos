/******************************************************************************
    NAME
	easyos_LH0(void, GetCC,
    LOCATION
	struct ExecBase *, SysBase, 88, Exec)
    FUNCTION
    INPUTS
    RESULT
    NOTES
    EXAMPLE
    BUGS
    SEE ALSO
    INTERNALS
    HISTORY
******************************************************************************/

	#include "machine.i"

	.text
	.balign 16
	.globl	easyos_SLIB_ENTRY(GetCC,Exec)
	.type	easyos_SLIB_ENTRY(GetCC,Exec),@function
easyos_SLIB_ENTRY(GetCC,Exec):
	/* This should be implemented in the jump table for speed. */
	move	%ccr,%d0
	rts


/******************************************************************************
    NAME
	easyos_LH0(void, SetSR,
    LOCATION
	struct ExecBase *, SysBase, 24, Exec)
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
	.globl	easyos_SLIB_ENTRY(SetSR,Exec)
	.type	easyos_SLIB_ENTRY(SetSR,Exec),@function
easyos_SLIB_ENTRY(SetSR,Exec):
	/* Dummy */
	rts

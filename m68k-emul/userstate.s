/******************************************************************************
    NAME
	easyos_LH0(void, UserState,
    LOCATION
	struct ExecBase *, SysBase, 26, Exec)
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
	.globl	easyos_SLIB_ENTRY(UserState,Exec)
	.type	easyos_SLIB_ENTRY(UserState,Exec),@function
easyos_SLIB_ENTRY(UserState,Exec):
	/* Dummy */
	rts

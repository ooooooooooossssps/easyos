/******************************************************************************
    NAME
        easyos_LH1(void, Supervisor,
    SYNOPSIS
	easyos_LHA(ULONG_FUNC, userFunction, A5),
    LOCATION
        struct ExecBase *, SysBase, 5, Exec)
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
	.globl	easyos_SLIB_ENTRY(Supervisor,Exec)
	.type	easyos_SLIB_ENTRY(Supervisor,Exec),@function
easyos_SLIB_ENTRY(Supervisor,Exec):
        /* The emulation has no real supervisor mode. */
	jmp (%a5)

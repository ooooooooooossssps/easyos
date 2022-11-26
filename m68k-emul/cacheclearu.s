/******************************************************************************
    NAME
	easyos_LH0(void, CacheControl,
    LOCATION
	struct ExecBase *, SysBase, 108, Exec)
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
	.globl	easyos_SLIB_ENTRY(CacheControl,Exec)
	.type	easyos_SLIB_ENTRY(CacheControl,Exec),@function
easyos_SLIB_ENTRY(CacheControl,Exec):
	/* Dummy */
	rts
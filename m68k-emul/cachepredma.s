/******************************************************************************
    NAME
	easyos_LH0(void, CachePreDMA,
    LOCATION
	struct ExecBase *, SysBase, 127, Exec)
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
	.globl	easyos_SLIB_ENTRY(CachePreDMA,Exec)
	.type	easyos_SLIB_ENTRY(CachePreDMA,Exec),@function
easyos_SLIB_ENTRY(CachePreDMA,Exec):
	/* Dummy */
	rts
/******************************************************************************
    NAME
	easyos_LH0(void, CachePostDMA,
    LOCATION
	struct ExecBase *, SysBase, 128, Exec)
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
	.globl	easyos_SLIB_ENTRY(CachePostDMA,Exec)
	.type	easyos_SLIB_ENTRY(CachePostDMA,Exec),@function
easyos_SLIB_ENTRY(CachePostDMA,Exec):
	/* Dummy */
	rts

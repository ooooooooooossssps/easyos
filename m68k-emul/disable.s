/******************************************************************************

    NAME
        easyos_LH0(void, Disable,

    LOCATION
        struct ExecBase *, SysBase, 20, Exec)

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
	.globl	easyos_SLIB_ENTRY(Disable,Exec)
	.type	easyos_SLIB_ENTRY(Disable,Exec),@function

easyos_SLIB_ENTRY(Disable,Exec):
	jbsr	easyos_CSYMNAME(os_disable)
#if !UseRegisterArgs
	move.l	%a6,-(%sp)
	
	/* Get SysBase */
	move.l	8(%sp),%a6
#endif

	/* increment nesting count and return */
	addq.b	#1,IDNestCnt(%a6)
#if !UseRegisterArgs
	move.l	(%sp)+,%a6
#endif
	rts
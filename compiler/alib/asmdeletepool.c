#define easyos_TAGRETURNTYPE APTR

#include "alib_intern.h"

/*****************************************************************************
    NAME */
#define NO_INLINE_STDARG /* turn off inline def */
#include <proto/exec.h>

        easyos_UFH2(void, AsmDeletePool,

/*  SYNOPSIS */
        easyos_UFHA(APTR, poolHeader, A0),
        easyos_UFHA(struct ExecBase *, SysBase, A6))

/*  FUNCTION
    INPUTS
    RESULT
    NOTES
    EXAMPLE
    BUGS
    SEE ALSO
    INTERNALS
    HISTORY
*****************************************************************************/
{
    easyos_USERFUNC_INIT
    DeletePool(poolHeader);
    easyos_USERFUNC_EXIT
} /* AsmDeletePool */

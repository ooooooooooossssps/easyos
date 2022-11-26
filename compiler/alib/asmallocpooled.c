#define easyos_TAGRETURNTYPE APTR

#include "alib_intern.h"

/*****************************************************************************
    NAME */
#define NO_INLINE_STDARG /* turn off inline def */
#include <proto/exec.h>

        easyos_UFH3(APTR, AsmAllocPooled,

/*  SYNOPSIS */
        easyos_UFHA(APTR, poolHeader, A0),
        easyos_UFHA(ULONG, memSize  , D0),
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

    return AllocPooled(poolHeader,memSize);

    easyos_USERFUNC_EXIT

} /* AsmAllocPooled */

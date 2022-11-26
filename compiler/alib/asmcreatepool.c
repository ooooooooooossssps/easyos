#define easyos_TAGRETURNTYPE APTR

#include "alib_intern.h"

/*****************************************************************************
    NAME */
#define NO_INLINE_STDARG /* turn off inline def */
#include <proto/exec.h>

        easyos_UFH4(APTR, AsmCreatePool,

/*  SYNOPSIS */
        easyos_UFHA(ULONG, MemFlags    , D0),
        easyos_UFHA(ULONG, PuddleSize  , D1),
        easyos_UFHA(ULONG, ThreshSize  , D2),
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
    return CreatePool(MemFlags, PuddleSize, ThreshSize);
    easyos_USERFUNC_EXIT
} /* AsmCreatePool */

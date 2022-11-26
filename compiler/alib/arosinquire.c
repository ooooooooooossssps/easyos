#define easyos_TAGRETURNTYPE  ULONG
#include <easyos/easyosbase.h>
#include "alib_intern.h"
#include <utility/tagitem.h>

extern struct Library * easyosBase;

/*****************************************************************************
    NAME */
#define NO_INLINE_STDARG /* turn off inline def */
#include <proto/easyos.h>

        ULONG easyosInquire(

/*  SYNOPSIS */
        ULONG tag1,
        ...)

/*  FUNCTION
    INPUTS
    RESULT
    NOTES
    EXAMPLE
    BUGS
    SEE ALSO
        easyos.library/easyosInquireA()
    INTERNALS
    HISTORY
*****************************************************************************/
{
    easyos_SLOWSTACKTAGS_PRE(tag1)

    retval = easyosInquireA(easyos_SLOWSTACKTAGS_ARG(tag1));

    easyos_SLOWSTACKTAGS_POST
} /* easyosInquire */

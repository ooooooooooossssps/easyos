#include <stdarg.h>
#include "easystruct_util.h"
#include <proto/intuition.h>
#include <proto/alib.h>

/*****************************************************************************
    NAME */

    struct Window * BuildEasyRequest (

/*  SYNOPSIS */
    struct Window       *RefWindow,
    struct EasyStruct   *easyStruct,
    ULONG               IDCMP,
    ...)

/*  FUNCTION
    INPUTS
    RESULT
    NOTES
    EXAMPLE
    BUGS
    SEE ALSO
    INTERNALS
*****************************************************************************/
{
    struct Window * retval;
    STRPTR format = CreateFormatStringFromEasyStruct(easyStruct);

    easyos_SLOWSTACKFORMAT_PRE_USING(IDCMP, format);
    retval = BuildEasyRequestArgs(RefWindow, easyStruct, IDCMP, easyos_SLOWSTACKFORMAT_ARG(format));
    easyos_SLOWSTACKFORMAT_POST(format);

    FreeFormatString(format);

    return retval;
} /* BuildEasyRequest */
Footer

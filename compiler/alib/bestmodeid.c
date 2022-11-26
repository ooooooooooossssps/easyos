#define easyos_TAGRETURNTYPE ULONG
#include <utility/tagitem.h>

/*****************************************************************************
    NAME */
#define NO_INLINE_STDARG /* turn off inline def */
#include <proto/graphics.h>

        ULONG BestModeID (

/*  SYNOPSIS */
        Tag tag1,
        ...)

/*  FUNCTION
        This is the varargs version of graphics.library/BestModeIDA().
        For information see graphics.library/BestModeIDA().
    INPUTS
    RESULT
    NOTES
    EXAMPLE
    BUGS
    SEE ALSO
        graphics.library/BestModeIDA()
    INTERNALS
    HISTORY
*****************************************************************************/
{
    easyos_SLOWSTACKTAGS_PRE(tag1)
    retval = BestModeIDA (easyos_SLOWSTACKTAGS_ARG(tag1));
    easyos_SLOWSTACKTAGS_POST
} /* BestModeID */
Footer

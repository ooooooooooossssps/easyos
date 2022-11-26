#define easyos_TAGRETURNTYPE APTR
#include <utility/tagitem.h>

/*****************************************************************************
    NAME */
#define NO_INLINE_STDARG /* turn off inline def */
#include <proto/dos.h>

        APTR AllocDosObjectTags (

/*  SYNOPSIS */
        ULONG type,
        Tag tag1,
        ...)

/*  FUNCTION
        This is the varargs version of dos.library/AllocDosObject().
        For information see dos.library/AllocDosObject().
    INPUTS
    RESULT
    NOTES
    EXAMPLE
    BUGS
    SEE ALSO
        dos.library/AllocDosObject()
    INTERNALS
    HISTORY
*****************************************************************************/
{
    easyos_SLOWSTACKTAGS_PRE(tag1)
    retval = AllocDosObject (type, easyos_SLOWSTACKTAGS_ARG(tag1));
    easyos_SLOWSTACKTAGS_POST
} /* AllocDosObjectTags */

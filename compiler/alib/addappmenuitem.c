#define easyos_TAGRETURNTYPE struct AppMenuItem *
#include <utility/tagitem.h>

/*****************************************************************************
    NAME */
#define NO_INLINE_STDARG /* turn off inline def */
#include <proto/workbench.h>

        struct AppMenuItem * AddAppMenuItem (

/*  SYNOPSIS */
        IPTR id,
        IPTR  userdata,
        STRPTR text,
        struct MsgPort * msgport,
        Tag tag1,
        ...)

/*  FUNCTION
        This is the varargs version of workbench.library/AddAppMenuItemA().
        For information see workbench.library/AddAppMenuItemA().
    INPUTS
    RESULT
    NOTES
    EXAMPLE
    BUGS
    SEE ALSO
        workbench.library/AddAppMenuItemA()
    INTERNALS
    HISTORY
*****************************************************************************/
{
    easyos_SLOWSTACKTAGS_PRE(tag1)
    retval = AddAppMenuItemA (id, userdata, text, msgport, easyos_SLOWSTACKTAGS_ARG(tag1));
    easyos_SLOWSTACKTAGS_POST
} /* AddAppMenuItem */

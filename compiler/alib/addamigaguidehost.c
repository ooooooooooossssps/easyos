#define easyos_TAGRETURNTYPE struct AppIcon *
#include <dos/bptr.h>
#include <utility/tagitem.h>

/*****************************************************************************
    NAME */
#define NO_INLINE_STDARG /* turn off inline def */
#include <proto/workbench.h>

        struct AppIcon * AddAppIcon (

/*  SYNOPSIS */
        IPTR id,
        IPTR  userdata,
        CONST_STRPTR text,
        struct MsgPort * msgport,
        BPTR lock,
        struct DiskObject * diskobj,
        Tag tag1,
        ...)

/*  FUNCTION
        This is the varargs version of workbench.library/AddAppIconA().
        For information see workbench.library/AddAppIconA().
    INPUTS
    RESULT
    NOTES
    EXAMPLE
    BUGS
    SEE ALSO
        workbench.library/AddAppIconA()
    INTERNALS
    HISTORY
*****************************************************************************/
{
    easyos_SLOWSTACKTAGS_PRE(tag1)
    retval = AddAppIconA (id, userdata, text, msgport, lock, diskobj, easyos_SLOWSTACKTAGS_ARG(tag1));
    easyos_SLOWSTACKTAGS_POST
} /* AddAppIcon */

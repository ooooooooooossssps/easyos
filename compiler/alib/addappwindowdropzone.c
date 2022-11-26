#define easyos_TAGRETURNTYPE struct AppWindowDropZone *
#include <dos/bptr.h>
#include <utility/tagitem.h>

/*****************************************************************************
    NAME */
#define NO_INLINE_STDARG /* turn off inline def */
#include <proto/workbench.h>

        struct AppWindowDropZone * AddAppWindowDropZone(

/*  SYNOPSIS */
        struct AppWindow * aw,
        IPTR               id,
        IPTR               userdata,
        Tag                tag1,
        ...)

/*  FUNCTION
        This is the varargs version of workbench.library/AddAppWindowDropZoneA().
        For information see workbench.library/AddAppWindowDropZoneA().
    INPUTS
    RESULT
    NOTES
    EXAMPLE
    BUGS
    SEE ALSO
        workbench.library/AddAppWindowDropZoneA()
    INTERNALS
    HISTORY
*****************************************************************************/
{
    easyos_SLOWSTACKTAGS_PRE(tag1)
    retval = AddAppWindowDropZoneA( aw, id, userdata, easyos_SLOWSTACKTAGS_ARG(tag1));
    easyos_SLOWSTACKTAGS_POST
} /* AddAppWindowDropZone */
Footer

#define easyos_TAGRETURNTYPE APTR
#include <utility/tagitem.h>


/*****************************************************************************
    NAME */
#include <libraries/asl.h>
#include <proto/asl.h>
extern struct Library *AslBase;
#undef AllocAslRequestTags /* Get rid of the macro from inline/ */

        APTR AllocAslRequestTags (

/*  SYNOPSIS */
        ULONG   reqType,
        Tag     tag1,
        ...)

/*  FUNCTION
        This is the varargs version of the asl.library AllocAslRequest().
        For information see asl.library/AllocAslRequest().
    INPUTS
        reqType     -   Type of requester to allocate.
        tag1        -   TagList of extra arguments.
    NOTES
    EXAMPLE
    BUGS
    SEE ALSO
        asl.library/AllocAslRequest()
    INTERNALS
    HISTORY
*****************************************************************************/
{
    easyos_SLOWSTACKTAGS_PRE(tag1)

    retval = AllocAslRequest(reqType, easyos_SLOWSTACKTAGS_ARG(tag1));

    easyos_SLOWSTACKTAGS_POST

} /* AllocAslRequestTags */

#include <proto/exec.h>

/*****************************************************************************
    NAME */
#include <exec/ports.h>
#include <proto/alib.h>

        void BeginIO (

/*  SYNOPSIS */
        struct IORequest * ioReq)

/*  FUNCTION
        Call the BeginIO() function of the given device.
    INPUTS
        ioReq - a filled out IORequest structure.
    RESULT
        None.
    NOTES
    EXAMPLE
    BUGS
    SEE ALSO
        exec.library/AbortIO()
    INTERNALS
    HISTORY
******************************************************************************/
{
    /* Call BeginIO() vector */
    easyos_LVO_CALL1NR(void,
        easyos_LCA(struct IORequest *,ioReq,A1),
        struct Device *,ioReq->io_Device,5,
    );
} /* BeginIO */
Footer

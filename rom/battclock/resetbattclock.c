#include "battclock_intern.h"

/*****************************************************************************
    NAME */
#include <proto/battclock.h>

        easyos_LH0(void, ResetBattClock,

/*  SYNOPSIS */
        /* void */

/*  LOCATION */
        APTR, BattClockBase, 1, Battclock)

/*  FUNCTION
        Reset the system battery-backed-up clock. This will reset the clock
        back to 0 seconds (or midnight, 1st Jan 1978).
    INPUTS
        None.
    RESULT
        The clock will be reset.
    NOTES
        This function may do nothing when the battery backed up clock either
        doesn't exist, or may not be writable by the operating system.
    EXAMPLE
    BUGS
    SEE ALSO
        ReadBattClock(), WriteBattClock()
    INTERNALS
*****************************************************************************/
{
    easyos_LIBFUNC_INIT

    WriteBattClock(0);

    easyos_LIBFUNC_EXIT
} /* ResetBattClock */
Footer

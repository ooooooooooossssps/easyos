#ifndef _easyos_INTERN_H_
#define _easyos_INTERN_H_

#include <exec/types.h>
#include <exec/libraries.h>
#include <dos/dos.h>

#include LC_LIBDEFS_FILE

/*
    This is the easyosBase structure. It is documented here because it is
    completely private. Applications should treat it as a struct Library, and
    use the easyos.library functions to get information.
*/

LIBBASETYPE
{
    struct Library       easyos_LibNode;
    APTR		 easyos_KernelBase;
};

#endif /* _easyos_INTERN_H */

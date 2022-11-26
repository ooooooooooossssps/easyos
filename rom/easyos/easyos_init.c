#include <easyos/symbolsets.h>
#include <proto/exec.h>

#include "easyos_intern.h"

#include LC_LIBDEFS_FILE

int easyos_Init(LIBBASETYPEPTR easyosBase)
{
    easyosBase->easyos_KernelBase = OpenResource("kernel.resource");
    
    return TRUE;
}

ADD2INITLIB(easyos_Init, 0);

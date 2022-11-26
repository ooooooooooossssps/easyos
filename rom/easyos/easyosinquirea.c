#include <easyos/config.h>
#include <exec/types.h>
#include <utility/tagitem.h>
#include <easyos/kernel.h>
#include <easyos/libcall.h>
#include <proto/kernel.h>
#include <proto/utility.h>

#include "easyos_intern.h"

#define DEBUG 0
#include <easyos/debug.h>
#undef kprintf

/* Kickstart ROM location offsets */
#define LOC_COOKIE  0x00
#define LOC_ADDRESS 0x04
#define LOC_MAJORV  0x0c
#define LOC_MINORV  0x0e
#define LOC_ROMSIZE 0x14    /* offset from end of ROM! */
#define ROM_END     0x1000000

#define easyos_VERSION_MAJOR      1
#define easyos_VERSION_MINOR      12
#define easyos_ABI_VERSION_MAJOR  -1      /* Change only value, name is used in external script */
#define easyos_RELEASE_DATE       7560    /* in days since 1978-01-01 */

#if (easyos_FLAVOUR & easyos_FLAVOUR_NATIVE)
/* Amiga hardware support functions */
IPTR kicksize(void);
IPTR kickbase(void);
#endif

/*****************************************************************************
    NAME */
#include <easyos/inquire.h>

        easyos_LH1(ULONG, easyosInquireA,

/*  SYNOPSIS */
        easyos_LHA(struct TagItem *, taglist, A0),

/*  LOCATION */
        struct easyosBase *, easyosBase, 5, easyos)

/*  FUNCTION
        This function is used to query system characteristics not easily
        queried with another function. All queries understood by this call
        will have appropriate values assigned to the location the query tag's
        ti_Data field points to.
    INPUTS
        tags - a tag list with appropriate queries. Each tag's ti_Data field
            should point to the location where the result of the query
            is to be stored. Do not forget to clear the location before, as
            queries not understood will be left untouched.
    TAGS
        AI_KickstartBase APTR
        AI_KickstartSize ULONG
        AI_KickstartVersion UWORD
        AI_KickstartRevision UWORD
            Only support these tags if we are on the native machine. On other
            machines this call will not touch the storage space. Set the
            storage space to 0 beforehand if you want to see if this call
            touches it.
        AI_easyosVersion IPTR
            easyos.library version masquerades as easyos version. This means
            that all easyos modules must have the same major version number.
        AI_easyosReleaseMajor IPTR
            Update this whenever a new easyos is released.
        AI_easyosReleaseMinor IPTR
            Update this whenever a new easyos is released.
        AI_easyosReleaseDate IPTR
            Update this whenever a new easyos is released.
        AI_easyosBuildDate IPTR
            Given in the format: <d>.<m>.<y>
        AI_easyosVariant IPTR
            Distribution name.
        AI_easyosArchitecture IPTR
            Return the target architecture.
        AI_easyosABIMajor IPTR
            Update this whenever a new ABI is introduced in easyos. Special
            value of -1 means that the ABI is under development and subject
            to change.
    RESULT
        index - the index of the first tag that could not be processed, plus
            one (e.g. 1 for taglist[0], 2 for taglist[1] etc.). Zero if all
            tags were handled.
    NOTES
    EXAMPLE
    BUGS
    SEE ALSO
        easyos/easyosbase.h
    INTERNALS
******************************************************************************/
{
    easyos_LIBFUNC_INIT

    APTR UtilityBase;
    struct TagItem *tag;
    ULONG ret = 0;
    int i = 0;
    IPTR data = 0;

    if (!(UtilityBase = TaggedOpenLibrary(TAGGEDOPEN_UTILITY)))
        return 1;

#   define SetData(tag,type,value)  \
    D(bug("   Data was: %d\n", *((type *)(tag->ti_Data)))); \
    (*((type *)(tag->ti_Data)) = value); \
    D(bug("   Data is : %d\n", *((type *)(tag->ti_Data))))

    D(bug("easyosInquireA(taglist=%p)\n", taglist));

    while( (tag = NextTagItem(&taglist)))
    {
        D(bug("  tag[%d] = 0x%lx  data = 0x%lx\n", i, tag->ti_Tag, tag->ti_Data));
        i++;

        switch(tag->ti_Tag)
        {

#if (easyos_FLAVOUR & easyos_FLAVOUR_NATIVE)
        /*
        Only support these tags if we are on the native machine. On other
        machines this call will not touch the storage space. Set the
        storage space to 0 if you want to see if this call touches it.
        */
        
        case AI_KickstartBase:
            SetData (tag, APTR, kickbase());
            break;
        
        case AI_KickstartSize:
            SetData (tag, ULONG, kicksize());
            break;
        
        case AI_KickstartVersion:
            SetData (tag, UWORD, *(UWORD *)(kickbase() + LOC_MAJORV));
            break;
        
        case AI_KickstartRevision:
            SetData (tag, UWORD, *(UWORD *)(kickbase() + LOC_MINORV));
            break;
#else
        case AI_KickstartSize:
            SetData (tag, ULONG, 0);
            break;

#endif

        case AI_easyosVersion:
            /*
            easyos.library version masquerades as easyos version. This means
            that all easyos modules must have the same major version number.
            */
            SetData (tag, IPTR, VERSION_NUMBER);
            break;
        
        case AI_easyosReleaseMajor:
            /* Update this whenever a new easyos is released */
            SetData (tag, IPTR, easyos_VERSION_MAJOR);
            break;
        
        case AI_easyosReleaseMinor:
            /* Update this whenever a new easyos is released */
            SetData (tag, IPTR, easyos_VERSION_MINOR);
            break;
        
        case AI_easyosReleaseDate:
            /* Update this whenever a new easyos is released */
            SetData (tag, IPTR, easyos_RELEASE_DATE);
            break;
        
        case AI_easyosBuildDate:
            SetData (tag, IPTR, (IPTR)__DATE__);
            break;

        /*
         * Reserved for distribution maintainers.
         * DO NOT set this to configure-time variant name. That name is used to identify
         * sub-architecture name, and changing it may break compatibility between
         * different easyos modules, especially on hosted. Full complete platform name
         * (including variant, if appropriate) is available via KATTR_Architecture
         * kernel's attribute.
         * Add one more configure option, or, better, provide some another way
         * (env variable, whatever).
         */
        case AI_easyosVariant:
#ifdef VARIANT
            SetData (tag, IPTR, (IPTR) VARIANT);
#else
            SetData (tag, IPTR, (IPTR) NULL);
#endif
            break;


        case AI_easyosABIMajor:
            SetData (tag, IPTR, easyos_ABI_VERSION_MAJOR);
            break;
        
        case AI_easyosArchitecture:
#ifdef KrnGetSystemAttr
            if (easyosBase->easyos_KernelBase)
            {
                APTR KernelBase = easyosBase->easyos_KernelBase;
                data = KrnGetSystemAttr(KATTR_Architecture);
            }
#else
            /*
             * This is a legacy hack for old PPC-native kernel.resource implementations.
             * Please do not support this. easyos.library is a part of base kickstart, and
             * it is platform-independent. Consequently, it should not include any hardcoded
             * references to platform name. Platform name is specified by kernel.resource.
             * See boot/modular_kickstart.txt for more info.
             */
            data = (IPTR)easyos_ARCHITECTURE;
#endif
            SetData(tag, IPTR, data);
            break;
        
        default:
            if (ret == 0)
                ret = i;
            break;
        
        }
    }

    CloseLibrary(UtilityBase);

    return ret;
    easyos_LIBFUNC_EXIT
} /* easyosInquireA */

#if (easyos_FLAVOUR & easyos_FLAVOUR_NATIVE)
/* Native easyos support functions */
IPTR kicksize(void)
{
    return *(ULONG *)(ROM_END - LOC_ROMSIZE);
}

IPTR kickbase(void)
{
    return (ROM_END - kicksize());
}
#endif

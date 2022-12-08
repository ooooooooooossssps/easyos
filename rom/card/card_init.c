#include "card_intern.h"

EASYOS_LH1(struct CardHandle*, OwnCard,
         EASYOS_LHA(struct CardHandle*, handle, A1),
         struct CardResource*, CardResource, 1, Card)
{
    EASYOS_LIBFUNC_INIT

    return NULL;

    EASYOS_LIBFUNC_EXIT
}

EASYOS_LH2(void, ReleaseCard,
         EASYOS_LHA(struct CardHandle*, handle, A1),
         EASYOS_LHA(ULONG, flags, D0),
         struct CardResource*, CardResource, 2, Card)
{
    EASYOS_LIBFUNC_INIT

    EASYOS_LIBFUNC_EXIT
}

EASYOS_LH0(struct CardMemoryMap*, GetCardMap,
        struct CardResource*, CardResource, 3, Card)
{
    EASYOS_LIBFUNC_INIT

    return &CardResource->cmm;

    EASYOS_LIBFUNC_EXIT
}

EASYOS_LH1(BOOL, BeginCardAccess,
        EASYOS_LHA(struct CardHandle*, handle, A1),
        struct CardResource*, CardResource, 4, Card)
{
    EASYOS_LIBFUNC_INIT

    return FALSE;

    EASYOS_LIBFUNC_EXIT
}

EASYOS_LH1(BOOL, EndCardAccess,
        EASYOS_LHA(struct CardHandle*, handle, A1),
        struct CardResource*, CardResource, 5, Card)
{
    EASYOS_LIBFUNC_INIT

    return FALSE;

    EASYOS_LIBFUNC_EXIT
}

EASYOS_LH0(UBYTE, ReadCardStatus,
         struct CardResource*, CardResource, 6, Card)
{
    EASYOS_LIBFUNC_INIT

    return 0;

    EASYOS_LIBFUNC_EXIT
}

EASYOS_LH2(BOOL, CardResetRemove,
        EASYOS_LHA(struct CardHandle*, handle, A1),
        EASYOS_LHA(ULONG, flag, D0),
        struct CardResource*, CardResource, 7, Card)
{
    EASYOS_LIBFUNC_INIT

    return FALSE;

    EASYOS_LIBFUNC_EXIT
}

EASYOS_LH2(UBYTE, CardMiscControl,
        EASYOS_LHA(struct CardHandle*, handle, A1),
        EASYOS_LHA(UBYTE, control_bits, D1),
        struct CardResource*, CardResource, 8, Card)
{
    EASYOS_LIBFUNC_INIT

    return 0;

    EASYOS_LIBFUNC_EXIT
}

EASYOS_LH2(ULONG, CardAccessSpeed,
        EASYOS_LHA(struct CardHandle*, handle, A1),
        EASYOS_LHA(ULONG, nanoseconds, D0),
        struct CardResource*, CardResource, 9, Card)
{
    EASYOS_LIBFUNC_INIT

    return 0;

    EASYOS_LIBFUNC_EXIT
}

EASYOS_LH2(LONG, CardProgramVoltage,
        EASYOS_LHA(struct CardHandle*, handle, A1),
        EASYOS_LHA(ULONG, voltage, D0),
        struct CardResource*, CardResource, 10, Card)
{
    EASYOS_LIBFUNC_INIT

    return -1;

    EASYOS_LIBFUNC_EXIT
}

EASYOS_LH1(BOOL, CardResetCard,
        EASYOS_LHA(struct CardHandle*, handle, A1),
        struct CardResource*, CardResource, 11, Card)
{
    EASYOS_LIBFUNC_INIT

    return FALSE;

    EASYOS_LIBFUNC_EXIT
}

EASYOS_LH4(BOOL, CopyTuple,
        EASYOS_LHA(struct CardHandle*, handle, A1),
        EASYOS_LHA(UBYTE*, buffer, A0),
        EASYOS_LHA(ULONG, tuplecode, D1),
        EASYOS_LHA(ULONG, size, D0),
        struct CardResource*, CardResource, 12, Card)
{
    EASYOS_LIBFUNC_INIT

    return FALSE;

    EASYOS_LIBFUNC_EXIT
}

EASYOS_LH2(BOOL, DeviceTuple,
        EASYOS_LHA(UBYTE*, tuple_data, A0),
        EASYOS_LHA(struct DeviceTData*, storage, A1),
        struct CardResource*, CardResource, 13, Card)
{
    EASYOS_LIBFUNC_INIT

    return FALSE;

    EASYOS_LIBFUNC_EXIT
}

EASYOS_LH1(struct Resident*, IfAmigaXIP,
        EASYOS_LHA(struct CardHandle*, handle, A2),
        struct CardResource*, CardResource, 14, Card)
{
    EASYOS_LIBFUNC_INIT

    return NULL;

    EASYOS_LIBFUNC_EXIT
}

EASYOS_LH0(ULONG, CardChangeCount,
        struct CardResource*, CardResource, 16, Card)
{
    EASYOS_LIBFUNC_INIT

    return 0;

    EASYOS_LIBFUNC_EXIT
}

EASYOS_LH0(BOOL, CardForceChange,
        struct CardResource*, CardResource, 15, Card)
{
    EASYOS_LIBFUNC_INIT

    return FALSE;

    EASYOS_LIBFUNC_EXIT
}

EASYOS_LH0(ULONG, CardInterface,
        struct CardResource*, CardResource, 17, Card)
{
    EASYOS_LIBFUNC_INIT

    return -1;

    EASYOS_LIBFUNC_EXIT
}
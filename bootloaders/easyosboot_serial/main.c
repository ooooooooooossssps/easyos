#include "cpu.h"
#include "panic.h"
#include "easyosboot/slot.h"
#include "easyosboot/serial.h"

static int _get_slot(void)
{
    uint32_t version = 0;
    int slot = -1;

    if (!IS_USED(MODULE_easyosBOOT_SLOT)) {
        return -1;
    }

    for (unsigned i = 0; i < easyosboot_slot_numof; i++) {
        const easyosboot_hdr_t *easyos_hdr = easyosboot_slot_get_hdr(i);
        if (easyosboot_slot_validate(i)) {
            /* skip slot if metadata broken */
            continue;
        }
        if (easyos_hdr->start_addr != easyosboot_slot_get_image_startaddr(i)) {
            continue;
        }
        if (slot == -1 || easyos_hdr->version > version) {
            version = easyos_hdr->version;
            slot = i;
        }
    }

    return slot;
}

static void _boot_default(int slot)
{
    if (!IS_USED(MODULE_easyosBOOT_SLOT)) {
        /* boot 'raw' firmware image */
        cpu_jump_to_image(SLOT0_OFFSET);
        return;
    }

    if (slot == -1) {
        slot = _get_slot();
    }

    if (slot != -1) {
        easyosboot_slot_jump(slot);
    }
}

void kernel_init(void)
{
    int slot = -1;

    if (IS_USED(MODULE_easyosBOOT_SERIAL)) {
        slot = easyosboot_serial_loader();
    }

    irq_disable();
    _boot_default(slot);

    /* serious trouble! nothing to boot */
    while (1) {}
}

NORETURN void core_panic(core_panic_t crash_code, const char *message)
{
    (void)crash_code;
    (void)message;
    while (1) {}
}

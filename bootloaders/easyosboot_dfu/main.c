#include "cpu.h"
#include "panic.h"
#include "easyosboot/slot.h"
#include "easyosboot/usb_dfu.h"
#include "ztimer.h"

#include "easyosboot/bootloader_selection.h"

#ifdef BTN_BOOTLOADER_PIN
#include "periph/gpio.h"
#endif

static bool _bootloader_alternative_mode(void)
{
#ifdef BTN_BOOTLOADER_PIN
    gpio_init(BTN_BOOTLOADER_PIN, BTN_BOOTLOADER_MODE);
    return (bool)gpio_read(BTN_BOOTLOADER_PIN) != BTN_BOOTLOADER_INVERTED;
#else
    return false;
#endif
}

void kernel_init(void)
{
    uint32_t version = 0;
    int slot = -1;

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

    /* Init ztimer before starting DFU mode */
    ztimer_init();

    /* Flash the unused slot if magic word is set */
    easyosboot_usb_dfu_init(0);

    if (slot != -1 && !_bootloader_alternative_mode()) {
        easyosboot_slot_jump(slot);
    }

    /* Nothing to boot, stay in DFU mode to flash a slot */
    easyosboot_usb_dfu_init(1);
}

NORETURN void core_panic(core_panic_t crash_code, const char *message)
{
    (void)crash_code;
    (void)message;
    while (1) {}
}

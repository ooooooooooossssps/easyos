#ifdef MODULE_USB_BOARD_RESET

#define USB_H_USER_IS_easyos_INTERNAL

#include "cpu.h"
#include "usb_board_reset.h"

/* Set the value used by the bootloader to select between boot in
   application and boot in bootloader mode. */
#define NRF52_DOUBLE_TAP_MAGIC_NUMBER       (0x4e)

void usb_board_reset_in_bootloader(void)
{
    NRF_POWER->GPREGRET = NRF52_DOUBLE_TAP_MAGIC_NUMBER;

    usb_board_reset_in_application();
}

#endif /* MODULE_USB_BOARD_RESET */

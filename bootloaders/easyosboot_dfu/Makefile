# Default easyos bootloader
APPLICATION = easyosboot_dfu

# Add easyosBOOT USB DFU integration
USEMODULE += easyosboot_usb_dfu

# Use xtimer for scheduled reboot
USEMODULE += ztimer
USEMODULE += ztimer_init

# USB device vendor and product ID
# pid.codes test VID/PID, not globally unique

# The VID/PID pair allocated for the easyos bootloader
# as allocated on https://pid.codes/1209/7D02/
USB_VID ?= 1209
USB_PID ?= 7D02

include ../easyosboot_common.mk
Footer

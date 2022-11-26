# Default testing board
BOARD ?= samr21-xpro

# Select the boards with easyosboot feature
FEATURES_REQUIRED += easyosboot

# Set easyosBOOT_BUILD to indicate a easyosboot application build
easyosBOOT_BUILD = 1
# Provide a define to detect if building the bootloader
CFLAGS += -DeasyosBOOT

# Disable unused modules
CFLAGS += -DNDEBUG -DLOG_LEVEL=LOG_NONE
DISABLE_MODULE += core_init core_msg core_panic
DISABLE_MODULE += auto_init auto_init_%
DISABLE_MODULE += pm_layered

# avoid using stdio
USEMODULE += stdio_null

# easyos codebase
easyosBASE ?= $(CURDIR)/../..

include $(easyosBASE)/Makefile.include

# limit easyosboot bootloader size
# TODO: Manage to set this variable for boards which already embed a
# bootloader, currently it will be overwritten
ROM_LEN := $(easyosBOOT_LEN)

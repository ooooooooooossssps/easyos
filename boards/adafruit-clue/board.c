#include "cpu.h"
#include "board.h"

#include "periph/gpio.h"

void board_init(void)
{
    /* initialize the screen backlight, turn it off by default */
    gpio_init(BACKLIGHT_PIN, GPIO_OUT);
    gpio_clear(BACKLIGHT_PIN);
}

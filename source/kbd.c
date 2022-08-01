#include "stdio.h"
#include "kbd.h"

void kbd_init(void)
{
    printf("kbd_init\n");
}

uint8_t kbd_read(uint8_t c)
{
    return c;
}
#include "stdio.h"
#include "defs.h"
#include "display.h"
#include "command.h"

int main(int argc, char *argv[])
{
    printf("main test\n");
    command_init();
    display_init();
    return 0;
}
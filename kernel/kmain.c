#include <kstdio.h>

void main()
{
    screen_clear();
    char *command = keyboard();
    write(command);
}
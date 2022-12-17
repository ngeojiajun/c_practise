#include "../../include/ui/ui.h"
#include <stdio.h>
#include <assert.h>

void ui_PrintHeader()
{
    printf("Welcome to the Practiser's Hunt\n");
    printf("v0.0.1\n");
    printf("(C) 2022 Jia Jun Ngeo\n");
    printf("Hit ? for help\n\n");
}

int ui_getInput(STRING **ptr)
{
    assert(ptr);
    // free the original object
    if (*ptr)
    {
        string_Free(*ptr);
    }
    char buf[100] = {0};
    // print the prompt
    printf("> ");
    // get the stuffs
    char *result = fgets(buf, 100, stdin);
    if (!result)
    {
        return 0;
    }
    // trim all the spaces
    string_RawTrimInplace(buf);
    *ptr = string_New(buf);
    return 1;
}

void ui_PrintHelp()
{
    printf("Work in progress\n");
    printf("Type quit to end the game\n");
    printf("\nAvailable commands:\n");
    printf("look [target]\t:Look for something. Targets are as below:\n");
    printf("\t\taround: For the surrounding objects\n");
    printf("go [direction] [distance=1]\t:Go to specific direction. Valid directions:\n");
    printf("\t\tnorth(n),south(s),west(w),east(e)\n");
    printf("inventory [actions]: inventory related commands. Valid actions:\n");
    printf("\t\tcoin: Show coin balance\n");
}
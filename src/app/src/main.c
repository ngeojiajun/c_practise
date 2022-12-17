#include "strings_utils.h"
#include "../include/ui/ui.h"
#include "../include/game/interpreter.h"
#include "../include/game/types.h"

int main(int argc, const char **argv)
{
    STRING *input = NULL;
    // print the header
    ui_PrintHeader();
    PLAYER_CONTEXT ctx;
    ctx.pos.x = 0;
    ctx.pos.y = 0;
    ctx.mapid = 0;
    ctx.coins = 100;
    ctx.inventories = array_New(1);
    // initialize the player context
    while (ui_getInput(&input) && game_InterpretCommand(input, &ctx))
    {
    }
    array_Destroy(ctx.inventories, NULL);
    return 0;
}
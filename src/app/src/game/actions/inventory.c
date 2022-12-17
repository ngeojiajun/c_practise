#include "strings_utils.h"
#include "../../../include/game/types.h"
#include "../../../include/game/definitions.h"
#include <stdio.h>

void action_Inventory(PLAYER_CONTEXT *ctx, STRING *params)
{
    // split the params into blocks
    PRAC_ARRAY *params_split = string_Split(params, " ");
    if (!params_split || params_split->filled != 1)
    {
        printf("I have no idea on what you want to do?\n");
        goto exit;
    }
    STRING **ptr = (STRING **)params_split->items;
    if (string_RawStringBeginsInsensitive(ptr[0]->string, "coin"))
    {
        printf("You have %d coins\n", ctx->coins);
    }
    else
    {
        printf("I have no idea on what you want to do?\n");
    }
exit:
    array_Destroy(params_split, string_Free);
}
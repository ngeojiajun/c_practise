#include "strings_utils.h"
#include "../../../include/game/types.h"
#include "../../../include/game/definitions.h"
#include <stdio.h>

void printItems(PLAYER_CONTEXT *ctx)
{
    printf("\n---Items-----\n");
    PRAC_ARRAY *inventories = ctx->inventories;
    ITEM **items = (ITEM **)inventories->items;
    if (!inventories->filled)
    {
        printf("Nothing inside the inventory\n");
    }
    else
    {
        for (int i = 0; i < inventories->filled; i++)
        {
            ITEM *entry = (items[i]);
            printf("%s\t(%d)\n", entry->base.tag, entry->quanntity);
        }
    }
    printf("\n");
}

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
    if (string_RawEqualsInsensitive(ptr[0]->string, "coin"))
    {
        printf("You have %d coins\n", ctx->coins);
    }
    else if (string_RawEqualsInsensitive(ptr[0]->string, "reveal"))
    {
        printItems(ctx);
    }
    else if (string_RawEqualsInsensitive(ptr[0]->string, "reveal_all"))
    {
        printf("You have %d coins\n", ctx->coins);
        printItems(ctx);
    }
    else
    {
        printf("I have no idea on what you want to do?\n");
    }
exit:
    array_Destroy(params_split, string_Free);
}
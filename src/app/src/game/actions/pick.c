#include "strings_utils.h"
#include "../../../include/game/types.h"
#include "../../../include/game/definitions.h"
#include "../../../include/game/utils.h"
#include <stdio.h>

static void pickNearbyItem(PLAYER_CONTEXT *ctx, LOCATION_2D direction)
{
    LOCATION_2D effective_pos = utils_Location2DAdd(direction, ctx->pos);
    LOCATION location = locations[ctx->mapid];
    OBJECT *lists = location.objects;
    OBJECT *obj = NULL;
    if (obj = utils_FindObjectAt(lists, location.object_length, effective_pos), obj)
    {
        switch (obj->type)
        {
        case OBJECT_TYPE_CHEST:
            // TODO move the items into the registry
            // add the coins
            CHEST_METADATA *metadata = (CHEST_METADATA *)obj->metadata;
            ctx->coins = metadata->coin;
            obj->valid = 0;
            printf("Yey, picked coins. Balance is now %d \n", ctx->coins);
            break;
        default:
            printf("Unknown object!!\n");
            return;
        }
    }
    else
    {
        printf("Nothing to pick at (%d,%d)\n", effective_pos.x, effective_pos.y);
    }
}

void action_Pick(PLAYER_CONTEXT *ctx, STRING *params)
{
    // split the params into blocks
    PRAC_ARRAY *params_split = string_Split(params, " ");
    if (!params_split || params_split->filled != 1)
    {
        printf("I have no idea on where you want to go?\n");
        goto exit;
    }
    STRING **ptr = (STRING **)params_split->items;
    if (MATCH_NOUN_2(ptr[0]->string, "left", "l"))
    {
        LOCATION_2D dir = {-1, 0};
        pickNearbyItem(ctx, dir);
    }
    else if (MATCH_NOUN_2(ptr[0]->string, "right", "r"))
    {
        LOCATION_2D dir = {1, 0};
        pickNearbyItem(ctx, dir);
    }
    else if (MATCH_NOUN_2(ptr[0]->string, "up", "u"))
    {
        LOCATION_2D dir = {0, 1};
        pickNearbyItem(ctx, dir);
    }
    else if (MATCH_NOUN_2(ptr[0]->string, "down", "d"))
    {
        LOCATION_2D dir = {0, -1};
        pickNearbyItem(ctx, dir);
    }
    else
    {
        printf("I have no idea on where you want to go?\n");
        goto exit;
    }
exit:
    array_Destroy(params_split, string_Free);
}
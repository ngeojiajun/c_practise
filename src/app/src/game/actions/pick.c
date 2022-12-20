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
            printf("Unimplemented\n");
            break;
        default:
            printf("Unknown object!!\n");
            return;
        }
    }
    else
    {
        printf("Nothing to pick at (%d,%d)\n", ctx->pos.x, ctx->pos.y);
    }
}

void action_Go(PLAYER_CONTEXT *ctx, STRING *params)
{
    // split the params into blocks
    PRAC_ARRAY *params_split = string_Split(params, " ");
    if (!params_split || params_split->filled != 1)
    {
        printf("I have no idea on where you want to go?\n");
        goto exit;
    }
exit:
    array_Destroy(params_split, string_Free);
}
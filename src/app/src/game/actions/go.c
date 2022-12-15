#include "strings_utils.h"
#include "../../../include/game/types.h"
#include "../../../include/game/definitions.h"
#include "../../../include/game/utils.h"
#include <stdio.h>

#define TRY_PARSE_DISTANCE                                                              \
    char *fail = NULL;                                                                  \
    long distance = params_split->filled == 1 ? 1 : strtoul(ptr[1]->string, &fail, 10); \
    if ((params_split->filled == 2 && *fail) || distance <= 0)                          \
    {                                                                                   \
        printf("Invalid distance!\n");                                                  \
    }                                                                                   \
    else

#define MATCH_NOUN_2(ref, match1, match2) (string_RawEqualsInsensitive(ref, match1) || string_RawEqualsInsensitive(ref, match2))

void checkAndMoveImpl(PLAYER_CONTEXT *ctx, LOCATION_2D pos)
{
    LOCATION_2D effective_pos = utils_Location2DAdd(pos, ctx->pos);
    // check weather it is in bound
    if (!utils_Location2DValidinLocation(&locations[ctx->mapid], effective_pos))
    {
        printf("Oops you went too far!!\n");
    }
    // check the obstacles
    LOCATION location = locations[ctx->mapid];
    OBJECT *lists = location.objects;
    for (int i = 0; i < location.object_length; i++)
    {
        OBJECT *obj = lists + i;
        if (!utils_Location2DCmp(effective_pos, obj->pos))
        {
            printf("Oops! Something is there! Use \"look around\" to get info!\n");
            return;
        }
    }
    ctx->pos = effective_pos;
    printf("You are now at (%d,%d)\n", ctx->pos.x, ctx->pos.y);
}

void action_Go(PLAYER_CONTEXT *ctx, STRING *params)
{
    // split the params into blocks
    PRAC_ARRAY *params_split = string_Split(params, " ");
    STRING **ptr = (STRING **)params_split->items;
    if (!params_split->filled || params_split->filled > 2)
    {
        printf("I have no idea on where you want to go?\n");
    }
    else if (MATCH_NOUN_2(ptr[0]->string, "north", "n"))
    {
        TRY_PARSE_DISTANCE
        {
            LOCATION_2D pos = {0, distance};
            checkAndMoveImpl(ctx, pos);
        }
    }
    else if (MATCH_NOUN_2(ptr[0]->string, "south", "s"))
    {
        TRY_PARSE_DISTANCE
        {
            LOCATION_2D pos = {0, -distance};
            checkAndMoveImpl(ctx, pos);
        }
    }
    else if (MATCH_NOUN_2(ptr[0]->string, "west", "w"))
    {
        TRY_PARSE_DISTANCE
        {
            LOCATION_2D pos = {-distance, 0};
            checkAndMoveImpl(ctx, pos);
        }
    }
    else if (MATCH_NOUN_2(ptr[0]->string, "east", "e"))
    {
        TRY_PARSE_DISTANCE
        {
            LOCATION_2D pos = {distance, 0};
            checkAndMoveImpl(ctx, pos);
        }
    }
    array_Destroy(params_split, string_Free);
}
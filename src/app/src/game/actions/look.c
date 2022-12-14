#include "strings_utils.h"
#include "../../../include/game/types.h"
#include "../../../include/game/definitions.h"
#include <stdio.h>

void action_Look(PLAYER_CONTEXT *ctx, STRING *params)
{
    if (string_RawEqualsInsensitive(params->string, "around"))
    {
        // looking around, so lets list out the entire list of objects
        LOCATION location = locations[ctx->mapid];
        OBJECT *lists = location.objects;
        printf("\nObjects surrounding yours:\n");
        for (int i = 0; i < location.object_length; i++)
        {
            OBJECT obj = lists[i];
            printf("%s (%s) at (%d,%d)",
                   obj.base.tag,
                   obj.base.description,
                   obj.pos.x,
                   obj.pos.y);
        }
        printf("\n\n");
    }
    else{
        printf("I have no idea on what you are looking for.\n");
    }
}
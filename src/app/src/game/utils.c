#include "../../include/game/utils.h"

OBJECT *utils_FindObjectAt(OBJECT *list_head, size_t count, LOCATION_2D loc)
{
    if (!list_head || !count)
    {
        return NULL;
    }
    for (int i = 0; i < count; i++)
    {
        OBJECT *ptr = list_head + count;
        if (ptr->pos.x == loc.x && ptr->pos.y == loc.y)
        {
            return ptr;
        }
    }
    return NULL;
}
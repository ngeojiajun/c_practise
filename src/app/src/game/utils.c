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
        if (!utils_Location2DCmp(loc,ptr->pos))
        {
            return ptr;
        }
    }
    return NULL;
}
int utils_Location2DCmp(LOCATION_2D lhs,LOCATION_2D rhs){
    int val=lhs.x-rhs.y;
    if(!val){
        return lhs.y-rhs.y;
    }
    return val;
}
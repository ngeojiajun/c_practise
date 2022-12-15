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
        if (!utils_Location2DCmp(loc, ptr->pos))
        {
            return ptr;
        }
    }
    return NULL;
}
int utils_Location2DCmp(LOCATION_2D lhs, LOCATION_2D rhs)
{
    int val = lhs.x - rhs.x;
    if (!val)
    {
        return lhs.y - rhs.y;
    }
    return val;
}
LOCATION_2D utils_Location2DAdd(LOCATION_2D lhs, LOCATION_2D rhs)
{
    LOCATION_2D return_val = {lhs.x + rhs.x, lhs.y + rhs.y};
    return return_val;
}
int utils_Location2DValidinLocation(LOCATION *loc, LOCATION_2D pos)
{
    if (!loc)
    {
        return 0;
    }
    // check is either of the component is <0
    if (pos.x < 0 || pos.y < 0)
    {
        return 0;
    }
    // check is either of the component is outside the boundary
    if (pos.x>(loc->max_pos.x)||pos.y>(loc->max_pos.y))
    {
        return 0;
    }
    return 1;
}
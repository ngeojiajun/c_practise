#include "types.h"

#define MATCH_NOUN_2(ref, match1, match2) (string_RawEqualsInsensitive(ref, match1) || string_RawEqualsInsensitive(ref, match2))

/**
 * Find a object at specific location
 */
OBJECT *utils_FindObjectAt(OBJECT *list_head, size_t count, LOCATION_2D loc);
/**
 * Compare the location coord
 */
int utils_Location2DCmp(LOCATION_2D lhs, LOCATION_2D rhs);
/**
 * Add coordinates together
 */
LOCATION_2D utils_Location2DAdd(LOCATION_2D lhs, LOCATION_2D rhs);
/**
 * Check is the position given is valid at the given location
 */
int utils_Location2DValidinLocation(LOCATION *loc, LOCATION_2D pos);
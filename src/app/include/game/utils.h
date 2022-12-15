#include "types.h"

/**
 * Find a object at specific location
 */
OBJECT* utils_FindObjectAt(OBJECT* list_head,size_t count,LOCATION_2D loc);
/**
 * Compare the location coord
*/
int utils_Location2DCmp(LOCATION_2D lhs,LOCATION_2D rhs);
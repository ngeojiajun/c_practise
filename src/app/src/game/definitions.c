/**
 * Hardcoded definition of the map
 */
#include "../../include/game/types.h"

OBJECT forest_object[] = { 
	{
		{"a","b"},
		{10,10}
	}
};
/**
 * All the definition of the objects and location
*/
extern LOCATION locations[] = {
	{
		{
			"forest",
			"A dark forest"
		},
	 forest_object,
	 sizeof(forest_object)/sizeof(OBJECT)
	}
};
extern const size_t location_length=sizeof(locations)/sizeof(LOCATION);
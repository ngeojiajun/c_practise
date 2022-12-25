/**
 * Hardcoded definition of the map
 */
#include "../../include/game/types.h"

CHEST_METADATA chest_data = {
	1000, NULL};

OBJECT forest_object[] = {{{"chest", "A chest with shining coins"}, {5, 5}, OBJECT_TYPE_CHEST, 1, &chest_data}};
/**
 * All the definition of the objects and location
 */
extern LOCATION locations[] = {
	{{"forest",
	  "A dark forest"},
	 forest_object,
	 sizeof(forest_object) / sizeof(OBJECT),
	 {10, 10}}};
extern const size_t location_length = sizeof(locations) / sizeof(LOCATION);
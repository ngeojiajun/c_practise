#pragma once
#include "array.h"
/**
 * The location in 2D
 */
typedef struct _LOCATION_2D
{
    int x, y;
} LOCATION_2D;
/**
 * General context of the player
 */
typedef struct _PLAYER_CTX
{
    int mapid;
    LOCATION_2D pos;
    /**
     * Inventories
     */
    PRAC_ARRAY *inventories;
} PLAYER_CONTEXT;

typedef struct _TAGGED_OBJECT
{
    const char *tag;
    const char *description;
} TAGGED_OBJECT;

typedef struct _OBJECT
{
    TAGGED_OBJECT base;
    LOCATION_2D pos;
} OBJECT;

/**
 * Locations -- Not for use by deserialization
 */
typedef struct{
    TAGGED_OBJECT base;
    OBJECT* objects;
    size_t object_length;
    LOCATION_2D max_pos;
} LOCATION;

#pragma once
#include <stdlib.h>
typedef struct _PROC_ARRAY
{
    void **items;
    size_t filled, allocated;
} PROC_ARRAY;
/**
 * The definition of the release function
*/
typedef void (*arrayItemRelease)(void*);

/**
 * Initialize a new array
 * @param length The length of the new array
 */
PROC_ARRAY *array_New(size_t length);
/**
 * Add a new item into the array
 * @param arr the array itself
 * @param item item
 */
void array_Push(PROC_ARRAY *arr, void *item);
/**
 * Remove the object at certain index
 * @param arr the array itself
 * @param idx item index
 * @param release the optional release function
 */
void array_RemoveAt(PROC_ARRAY *arr, size_t idx,arrayItemRelease release);
/**
 * Destroy the entire array
 * @param arr the array itself
 * @param release the optional release function
 */
void array_Destroy(PROC_ARRAY* arr,arrayItemRelease release);
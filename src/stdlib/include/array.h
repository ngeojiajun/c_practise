#pragma once
#include <stdlib.h>
typedef struct _PRAC_ARRAY
{
    void **items;
    size_t filled, allocated;
} PRAC_ARRAY;
/**
 * The definition of the release function
*/
typedef void (*arrayItemRelease)(void*);

/**
 * Initialize a new array
 * @param length The length of the new array
 */
PRAC_ARRAY *array_New(size_t length);
/**
 * Add a new item into the array
 * @param arr the array itself
 * @param item item
 */
void array_Push(PRAC_ARRAY *arr, void *item);
/**
 * Remove the object at certain index
 * @param arr the array itself
 * @param idx item index
 * @param release the optional release function
 */
void array_RemoveAt(PRAC_ARRAY *arr, size_t idx,arrayItemRelease release);
/**
 * Destroy the entire array
 * @param arr the array itself
 * @param release the optional release function
 */
void array_Destroy(PRAC_ARRAY* arr,arrayItemRelease release);
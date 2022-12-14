#pragma once
#include <stdlib.h>
#include "array.h"

typedef struct _PRAC_STRING{
    char* string;
    size_t length;
}STRING;

/**
 * Allocate a new string from the `base`
 * @param base The base content for the string
*/
STRING* string_New(const char* base);

/**
 * Make a duplicate of a string which is part of the string
 * @param base the string to be duplicated
 * @param start the index of the string which become the first char (inclusive)
 * @param end the index of the string which ends the string (exclusive)
*/
STRING* string_Slice(const STRING* base,size_t start,size_t end);

/**
 * Free the object
*/
void string_Free(STRING* obj);

/**
 * Raw case insensitive comparision function
 * @returns 0 when not match, 1 otherwise
*/
int string_RawEqualsInsensitive(const char* a,const char* b);
/**
 * Trim the string given
*/
void string_RawTrimInplace(char* ptr);

/**
 * Trim the string given
*/
void string_TrimInplace(STRING* base);

/**
 * Check is the string starts with another (insensitive)
*/
int string_RawStringBeginsInsensitive(const char* a,const char*b);

/**
 * Split the string into array by the separator
 * @param base the string to be split
 * @param separator separator to use
 * @returns the split array, use string_Free as the disposer
*/
PRAC_ARRAY* string_Split(STRING* base, const char* separator);
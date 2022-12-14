#include "../include/strings_utils.h"
#include "../include/math.h"
#include <string.h>
#include <ctype.h>

inline STRING *string_NewEmpty()
{
    STRING *ret = malloc(sizeof(STRING));
    ret->length = 0;
    ret->string = malloc(1);
    ret->string[0] = 0;
    return ret;
}

STRING *string_New(const char *base)
{
    if (!base)
    {
        return NULL;
    }
    STRING *return_val = malloc(sizeof(STRING));
    if (!return_val)
    {
        return NULL;
    }
    return_val->length = strlen(base);
    return_val->string = _strdup(base);
    return return_val;
}

STRING *string_Slice(const STRING *base, size_t start, size_t end)
{
    if (!base)
    {
        return NULL;
    }
    // check the string length
    if (start > base->length)
    {
        return string_NewEmpty();
    }
    // prepare a new object
    STRING *return_val = malloc(sizeof(STRING));
    if (!return_val)
    {
        return NULL;
    }
    // calculate the new length of the object
    return_val->length = PRAC_MIN(base->length - start, end - start);
    return_val->string = malloc(return_val->length + 1);
    if (!return_val->string)
    {
        free(return_val);
        return NULL;
    }
    memset(return_val->string, 0, return_val->length + 1);
    strncpy(return_val->string, base->string + start, return_val->length);
    return return_val;
}
void string_Free(STRING *obj)
{
    if (obj)
    {
        free(obj->string);
        free(obj);
    }
}

int string_RawEqualsInsensitive(const char *a, const char *b)
{
    size_t length = strlen(a);
    if (length != strlen(b))
    {
        return 0;
    }
    const unsigned char *_a = a;
    const unsigned char *_b = b;
    for (int i = 0; i < length; i++)
    {
        if (tolower(_a[i]) != tolower(_b[i]))
        {
            return 0;
        }
    }
    return 1;
}
void string_RawTrimInplace(char *ptr)
{
    size_t length = strlen(ptr);
    if (!length)
    {
        return;
    }
    // trim away the space at end
    while (isspace(ptr[length - 1]))
    {
        length--;
    }
    ptr[length] = 0;
    size_t i = 0;
    // trim away the space at front
    while (isspace(ptr[i]))
    {
        i++;
        length--;
    }
    if (i > 0)
    {
        memcpy(ptr, ptr + i, length);
        ptr[length] = 0;
    }
}
void string_TrimInplace(STRING *base)
{
    size_t length = base->length;
    if (!length)
    {
        return;
    }
    char *ptr = base->string;
    // trim away the space at end
    while (isspace(ptr[length - 1]))
    {
        length--;
    }
    ptr[length] = 0;
    size_t i = 0;
    // trim away the space at front
    while (isspace(ptr[i]))
    {
        i++;
        length--;
    }
    if (i > 0)
    {
        memcpy(ptr, ptr + i, length);
        ptr[length] = 0;
    }
    // update the length
    base->length = length;
}
int string_RawStringBeginsInsensitive(const char *a, const char *b)
{
    size_t length = PRAC_MIN(strlen(a), strlen(b));
    const unsigned char *_a = a;
    const unsigned char *_b = b;
    for (int i = 0; i < length; i++)
    {
        if (tolower(_a[i]) != tolower(_b[i]))
        {
            return 0;
        }
    }
    return 1;
}
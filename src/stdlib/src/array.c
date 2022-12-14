#include "array.h"
#include <memory.h>

PROC_ARRAY* array_New(size_t length){
    PROC_ARRAY* return_val=malloc(sizeof(PROC_ARRAY));
    if(!return_val){
        return NULL;
    }
    memset(return_val,0,sizeof(PROC_ARRAY));
    if(length){
        return_val->allocated=length;
        return_val->items=malloc(length*sizeof(void*));
        if(!return_val->items){
            free(return_val);
            return NULL;
        }
    }
    return return_val;
}
void array_Push(PROC_ARRAY* arr,void* item){
    if(!arr){
        return;
    }
    //check the space
    if(arr->filled+1>=arr->allocated){
        //try to reallocate the memory
        const size_t target_size=arr->allocated+10;
        void** reallocated=realloc(arr->items,target_size*sizeof(void*));
        if(!reallocated){
            reallocated=malloc(target_size*sizeof(void*));
            if(!reallocated){
                return;
            }
            memcpy(realloc,arr->items,arr->allocated*sizeof(void*));
            free(arr->items);
        }
        arr->allocated=target_size;
    }
    //fill in the content
    arr->items[arr->filled++]=item;
}
void array_RemoveAt(PROC_ARRAY *arr, size_t idx,arrayItemRelease release){
    if(!arr||idx>=arr->filled){
        return;
    }
    //get the index
    //0,1,2,3,4,5
    size_t copy_length=arr->filled-idx;
    //release the object
    if(release){
        release(arr->items[idx]);
    }
    memcpy(arr->items+idx,arr->items+idx+1,sizeof(void*)*copy_length);
    --arr->filled;
}
void array_Destroy(PROC_ARRAY* arr,arrayItemRelease release){
    if(!arr){
        return;
    }
    while(arr->filled){
        array_RemoveAt(arr,0,release);
    }
    free(arr->items);
    free(arr);
}
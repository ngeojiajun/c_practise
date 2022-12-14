#include "../../include/ui/ui.h"
#include <stdio.h>
#include <assert.h>

void ui_PrintHeader(){
    printf("Welcome to the Practiser's Hunt\n");
    printf("(C) 2022 Jia Jun Ngeo\n");
    printf("Hit ? for help\n\n");
}

int ui_getInput(STRING** ptr){
    assert(ptr);
    //free the original object
    if(*ptr){
        string_Free(*ptr);
    }
    char buf[100]={0};
    //print the prompt
    printf("> ");
    //get the stuffs
    char* result=fgets(buf,100,stdin);
    if(!result){
        return 0;
    }
    //trim all the spaces
    string_RawTrimInplace(buf);
    *ptr=string_New(buf);
    return 1;
}
//Common logic on UI
#pragma once
#include "strings_utils.h"

/**
 * Print the application header
*/
void ui_PrintHeader();
/**
 * Get the response from the user
 * @param ptr the pointer to hold the object
*/
int ui_getInput(STRING** ptr);
/**
 * Print out the help
*/
void ui_PrintHelp();
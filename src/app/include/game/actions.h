#include "strings_utils.h"
#include "types.h"
#pragma once

/**
 * look command implementation
 * subparams:
 * around - check the stuffs around
*/
void action_Look(PLAYER_CONTEXT* ctx,STRING* params);
/**
 * go command implementation
 * subparams:
 * north/n [steps]
 * south/s [steps]
 * west/w [steps]
 * east/e [steps]
*/
void action_Go(PLAYER_CONTEXT* ctx,STRING* params);
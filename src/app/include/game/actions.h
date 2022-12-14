#include "strings_utils.h"
#include "types.h"
#pragma once

/**
 * look command implementation
 * subparams:
 * around - check the stuffs around
 */
void action_Look(PLAYER_CONTEXT *ctx, STRING *params);
/**
 * go command implementation
 * subparams:
 * north/n [steps]
 * south/s [steps]
 * west/w [steps]
 * east/e [steps]
 */
void action_Go(PLAYER_CONTEXT *ctx, STRING *params);
/**
 * inventory command implementation
 * subparams:
 * reveal - reveal the items list inside the inventory
 * coins - reveal the coin balance
 * reveal_all - reveal all information
 */
void action_Inventory(PLAYER_CONTEXT *ctx, STRING *params);
/**
 * pick command implementation
 * ->pick a object near player
 * format:
 * pick [direction]
 * directions:
 * left/l
 * right/r
 * up/u
 * down/d
*/
void action_Pick(PLAYER_CONTEXT *ctx,STRING* params);
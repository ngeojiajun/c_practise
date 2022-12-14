#include "../../include/game/interpreter.h"
#include "../../include/game/types.h"
#include "../../include/game/definitions.h"
#include "../../include/game/actions.h"
#include "../../include/ui/ui.h"
#include <stdio.h>

int game_InterpretCommand(STRING* cmd, PLAYER_CONTEXT* ctx)
{
	if (!cmd || !ctx)
	{
		return 0;
	}
	char* cmd_string = cmd->string;
	if (string_RawEqualsInsensitive(cmd_string, "quit") ||
		!strcmp(cmd_string, "q"))
	{
		return 0;
	}
	else if (string_RawEqualsInsensitive(cmd_string, "where am i"))
	{
		printf("You are at %s on(%d,%d)\n",
			locations[ctx->mapid].base.tag,
			ctx->pos.x,
			ctx->pos.y);
	}
	else if(string_RawStringBeginsInsensitive(cmd_string,"look ")){
		//create a new string here with the command removed
		STRING* params=string_Slice(cmd,5,cmd->length);
		//strip the surrounding space
		string_TrimInplace(params);
		action_Look(ctx,params);
		string_Free(params);
	}
	else if (string_RawEqualsInsensitive(cmd_string, "?"))
	{
		ui_PrintHelp();
	}
	else
	{
		printf("I dont know what you want??\n");
	}
	return 1;
}

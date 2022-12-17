#include "../../include/game/interpreter.h"
#include "../../include/game/types.h"
#include "../../include/game/definitions.h"
#include "../../include/game/actions.h"
#include "../../include/ui/ui.h"
#include <stdio.h>

#define STRLEN(s) ((sizeof(s) / sizeof(s[0])) - sizeof(s[0]))

#define DEFINE_ACTION(command, handler)                                   \
	else if (string_RawStringBeginsInsensitive(cmd_string, command))      \
	{                                                                     \
		STRING *params = string_Slice(cmd, STRLEN(command), cmd->length); \
		string_TrimInplace(params);                                       \
		handler(ctx, params);                                             \
		string_Free(params);                                              \
	}

int game_InterpretCommand(STRING *cmd, PLAYER_CONTEXT *ctx)
{
	if (!cmd || !ctx)
	{
		return 0;
	}
	char *cmd_string = cmd->string;
	if (string_RawEqualsInsensitive(cmd_string, "quit") ||
		string_RawEqualsInsensitive(cmd_string, "exit") ||
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
	DEFINE_ACTION("look ", action_Look)
	DEFINE_ACTION("go ", action_Go)
	DEFINE_ACTION("inventory ", action_Inventory)
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

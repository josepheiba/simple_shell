#include "main.h"

int summon_tokens(char *cmd, char **args, int num_chars)
{
	char *token;
	char *cmdup;
	int i;

	i = 0;
	cmdup = cmd;
	while ((token = strtok(cmdup, " \n")) != NULL)
	{
		cmdup = NULL;
		args = realloc(args, sizeof(char *) * (i + 1));
		if (args == NULL)
			return(-1);
		args[i] = malloc(sizeof(token));
		if (args[i] == NULL)
			return(-1);
		_strcpy(args[i], token);
		i++;
	}
		args = realloc(args, sizeof(char *) * (i + 1));
		if (args == NULL)
			return(-1);
		args[i] = NULL;

	if (num_chars != 0)
		return(i);
	return (0);
}

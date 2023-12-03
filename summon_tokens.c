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
		args[i] = malloc(sizeof(token));
		if (args[i] == NULL)
			return(-1);
		_strcpy(args[i], token);
		i++;
	}
		args[i] = NULL;

	if (num_chars != 0)
		return(i);
	return (0);
}

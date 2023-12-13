#include "main.h"

int summon_tokens(char *cmd, char **args)
{
	char *token;
	char *cmdup;
	int i, k;

	i = 0;

	cmdup = cmd;
	while ((token = strtok(cmdup, " \n;")) != NULL)
	{
		if (token[0] == '#')
			break;
		cmdup = NULL;
		args[i] = malloc(sizeof(char) * (_strlen_recursion(token) + 1));
		if (args[i] == NULL)
		{
			for (k = 0; k < i; k++)
				free(args[k]);
			status = 2;
			return(-1);
		}
		_strcpy(args[i], token);
		i++;
	}
	args[i] = NULL;

	return(i);
}

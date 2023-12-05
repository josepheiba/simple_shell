#include "main.h"

int summon_tokens(char *cmd, char **args, int num_chars)
{
	char *token;
	char *cmdup;
	int i;

	i = 0;
	cmdup = cmd;
	while ((token = strtok(cmdup, " \n\0")) != NULL)
	{
		cmdup = NULL;
		args[i] = malloc(sizeof(char) * (_strlen_recursion(token) + 1));
		if (args[i] == NULL)
			return(-1);
		_strcpy(args[i], token);
		i++;
	}
        if (i != 0)
        {
		args[i] = NULL;
        }

	if (num_chars != 0)
		return(i);
	return (0);
}

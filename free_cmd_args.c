#include "main.h"

int free_cmd_args(char *cmd, char **args, int free_index)
{
	int i;

	i = 0;
	while (i < free_index)
	{
		free(args[i]);
		i++;
	}
	free(args);
	free(cmd);
	return (0);
}

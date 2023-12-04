#include "main.h"

int free_cmd_args(char **cmd, char **args, int free_index)
{
	int i;

	for (i = 0; i < free_index; i++)
		free(args[i]);
	free(*cmd);
	return (0);
}

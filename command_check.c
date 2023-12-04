#include "main.h"

int command_check(char **cmd, char **path, char **pths, int path_index)
{
	int i, j;
	char *commands[] = {"exit\n", NULL};

	i = 0;
	while(i < 1 && commands[i] != NULL)
	{
		if(_strcmp(*cmd, commands[i]) == 0)
		{
			for (j = 0; j < path_index; j++)
				free(pths[j]);
			free(*cmd);
			free(*path);
			_exit(i);
		}
		i++;
	}
	return(0);
}

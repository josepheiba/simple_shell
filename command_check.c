#include "main.h"

int command_check(char **cmd, char **path, char **pths, int path_index, char **environ)
{
	int i, j;
	char *commands[] = {"exit\n", NULL};
	(void) environ;

	i = 0;
	while(commands[i] != NULL)
	{
		if(_strcmp(*cmd, commands[i]) == 0)
		{
			if (i == 0)
			{
				for (j = 0; j < path_index; j++)
					free(pths[j]);
				free(*path);
				free(*cmd);
				_exit(0);
			}
		}
		i++;
	}
	return(0);
}

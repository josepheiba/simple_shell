#include "main.h"

int command_check(char **cmd, char **path, char **pths, int path_index, char **environ)
{
	int i, j, index;
	char *commands[] = {"exit\n", "env\n", NULL};
	char end = '\n';

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
			else if (i == 1)
			{
				for (index = 0; environ[index] != NULL; index++)
				{
					write(1, environ[index], _strlen_recursion(environ[index]));
					write(1, &end, 1);
				}
				return (-1);
			}
		}
		i++;
	}
	return(0);
}

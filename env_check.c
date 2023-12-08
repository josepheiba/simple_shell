#include "main.h"

int env_check(char **cmd, char **args, char **path, char **pths, int args_index, int path_index, char **environ)
{
	int i, index;
	char *commands[] = {"env\n", NULL};
	char end = '\n';
	(void) cmd;
	(void) path;
	(void) pths;
	(void) args_index;
	(void) path_index;

	i = 0;
	while(commands[i] != NULL)
	{
		if(_strcmp(args[0], commands[i]) == 0)
		{
			for (index = 0; environ[index] != NULL; index++)
			{
				write(1, environ[index], _strlen_recursion(environ[index]));
				write(1, &end, 1);
			}
			return(1);
		}
		i++;
	}
	return(0);
}

#include "main.h"

/**
 * env_check - check code.
 * cmd : variable
 * path : variable
 * path : variable
 * pths : variable
 * args_index : variable
 * path_index : variable
 * myenviron : variable
 * Return: check declaration
 */

int env_check(char **cmd, char **args, char **path, char **pths, int args_index, int path_index, char **myenviron)
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
			for (index = 0; myenviron[index] != NULL; index++)
			{
				write(1, myenviron[index], _strlen_recursion(myenviron[index]));
				write(1, &end, 1);
			}
			return(1);
		}
		i++;
	}
	return(0);
}

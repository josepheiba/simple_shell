#include "main.h"

int setenv_check(char **cmd, char **args, char **path, char **pths, int args_index, int path_index, char **myenviron)
{
	int i, index;
	char *commands[] = {"setenv\n", NULL};
	char *equals = "=";
	char *temp1, *temp2;
	(void) cmd;
	(void) path;
	(void) pths;
	(void) args_index;
	(void) path_index;

	i = 0;
	while(commands[i] != NULL)
	{
		index = 0;
		while (myenviron[index] != NULL)
			index++;

		if (_strcmp(args[0], commands[i]) == 0 && args[1] != NULL && args[2] != NULL)
		{
			temp1 = str_concat(args[1], equals);
			temp2 = str_concat(temp1, args[2]);
			myenviron[index] = malloc(sizeof(char)
						* (_strlen_recursion(args[1]) + 2 + _strlen_recursion(args[2])));
			_strcpy(myenviron[index], temp2);
			myenviron[index + 1] = NULL;
			free(temp1);
			free(temp2);
			return (1);
		}
		else if (_strcmp(args[0], commands[i]) == 0)
			return (1);
		i++;
	}
	return(0);
}

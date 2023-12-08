#include "main.h"

int unsetenv_check(char **cmd, char **args, char **path, char **pths, int args_index, int path_index, char **myenviron)
{
	int i, index;
	char *commands[] = {"unsetenv\n", NULL};
	(void) cmd;
	(void) path;
	(void) pths;
	(void) args_index;
	(void) path_index;

	i = 0;
	while(commands[i] != NULL)
	{

		if (_strcmp(args[0], commands[i]) == 0 && args[1] != NULL)
		{
			index = 0;
			while (myenviron[index] != NULL && _unset_strcmp(myenviron[index], args[1]) != 0)
				index++;

			if (myenviron[index] != NULL)
			{
				free(myenviron[index]);

				while (myenviron[index] != NULL)
				{
					myenviron[index] = myenviron[index + 1];
					index++;
				}
			}
			return (1);
		}
		else if (_strcmp(args[0], commands[i]) == 0)
			return (1);
		i++;
	}
	return(0);
}

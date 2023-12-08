#include "main.h"

int setenv_check(char **cmd, char **args, char **path, char **pths, int args_index, int path_index, char **environ)
{
	int i, index;
	char *commands[] = {"setenv\n", NULL};
	char *equals = "=";
	(void) cmd;
	(void) path;
	(void) pths;
	(void) args_index;
	(void) path_index;

	i = 0;
	while(commands[i] != NULL)
	{
		if(_strcmp(args[0], commands[i]) == 0 && args[1] != NULL && args[2] != NULL)
		{
			index = 0;
			while (environ[index] != NULL)
				index++;

			environ = realloc(environ, sizeof(*environ) * (index + 2));
			environ[index + 1] = malloc(sizeof(char)
				       	* (_strlen_recursion(args[1] + 2 + _strlen_recursion(args[2])))); 
			environ[index + 1] = str_concat(args[1], (str_concat(equals, args[2])));
			environ[index + 2] = NULL;
			return(1);
		}
		i++;
	}
	return(0);
}

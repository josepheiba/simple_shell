#include "main.h"

int exit_check(char **cmd, char **args, char **path, char **pths, int args_index, int path_index, char **myenviron)
{
	int i, j, k, l;
	int code, arg_count;
	char *commands[] = {"exit\n", NULL};
	char *error_start = "./hsh: 1: exit: Illegal number: ";
	char end = '\n';
	char string[100];

	arg_count = i = 0;
	while(commands[i] != NULL)
	{
		if(_strcmp(args[0], commands[i]) == 0)
		{
			if (args[1] != NULL)
			{
				arg_count = 1;
				code = _atoi(args[1]);
				for (k = 0; args[1][k] != '\0'; k++)
					string[k] = args[1][k];
				string[k] = '\0';
			}
			for (j = 0; j < path_index; j++)
				free(pths[j]);
			free(*path);
			for (i = 0; i < args_index; i++)
				free(args[i]);
			free(*cmd);
			for (l = 0; myenviron[l] != NULL; l++)
				free(myenviron[l]);
			if (arg_count == 0)
				_exit(0);
			if (code <= 0)
			{
				write(2, error_start, _strlen_recursion(error_start));
				write(2, string, _strlen_recursion(string));
				write(2, &end, 1);
				_exit(2);
			}
			_exit(code);
		}
		i++;
	}
	return(0);
}

#include "main.h"

int if_path_command_exist(char **pths, char *argzero)
{
	int i;
	char *path_argzero;

	for (i = 0; pths[i] != NULL; i++)
	{
		path_argzero = str_concat(pths[i], argzero);
		if (access(path_argzero, F_OK) == 0)
		{
			free(path_argzero);
			return (i);
		}
		else
		{
			free(path_argzero);
		}
	}
	return (0);
}

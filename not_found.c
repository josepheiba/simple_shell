#include "main.h"

int not_found(char *argzero, char **cmd, char **args, char **path, char **pths, int path_index)
{
        char *error_start = "./hsh: 1: ";
        char *error_notfound = ": not found\n";
	int i, j;

        write(2, error_start, _strlen_recursion(error_start));
        write(2, argzero, _strlen_recursion(argzero));
        write(2, error_notfound, _strlen_recursion(error_notfound));

	for (i = 0; args[i] != NULL; i++)
		free(args[i]);
	for (j = 0; j < path_index; j++)
		free(pths[j]);
	free(*cmd);
	free(*path);
	_exit(127);
        return (127);
}

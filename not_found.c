#include "main.h"

int not_found(char *argzero, char **cmd, char **args, char **path, char **pths, int path_index)
{
	int i, j;

        char *error_start = "./hsh: 1: ";
        char *error_notfound = ": not found\n";
	write(STDERR_FILENO, error_start, _strlen_recursion(error_start));
	write(STDERR_FILENO, argzero, _strlen_recursion(argzero));
	write(STDERR_FILENO, error_notfound, _strlen_recursion(error_notfound));

	for (i = 0; args[i] != NULL; i++)
		free(args[i]);
	for (j = 0; j < path_index; j++)
		free(pths[j]);
	free(*cmd);
	free(*path);
	_exit(127);
        return (127);
}

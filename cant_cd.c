#include "main.h"

int cant_cd(char *foldername)
{
        char *error_start = "./hsh: 1: ";
        char *error_notfound = "cd: can't cd to ";
        char *end = "\n";

	write(STDERR_FILENO, error_start, _strlen_recursion(error_start));
	write(STDERR_FILENO, error_notfound, _strlen_recursion(error_notfound));
	write(STDERR_FILENO, foldername, _strlen_recursion(foldername));
	write(STDERR_FILENO, end, _strlen_recursion(end));
	 
	/*
	int i, j;
	for (i = 0; args[i] != NULL; i++)
		free(args[i]);
	for (j = 0; j < path_index; j++)
		free(pths[j]);
	free(*cmd);
	free(*path);
	_exit(127);
	*/
	status = 0;
        return (0);
}

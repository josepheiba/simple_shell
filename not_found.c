#include "main.h"

int not_found(char *argzero)
{
        char *error_start = "./hsh: 1: ";
        char *error_notfound = ": not found\n";
        write(2, error_start, _strlen_recursion(error_start));
        write(2, argzero, _strlen_recursion(argzero));
        write(2, error_notfound, _strlen_recursion(error_notfound));
	_exit(127);
        return (127);
}

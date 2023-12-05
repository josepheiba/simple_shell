#include "main.h"

int not_found(char *argzero)
{
        char *error_start = "./hsh: 1: ";
        char *error_notfound = ": not found";
        write(1, error_start, _strlen_recursion(error_start));
        write(1, argzero, _strlen_recursion(argzero));
        write(1, error_notfound, _strlen_recursion(error_notfound));
        return (0);
}

#include "main.h"

int builtin_check(char **cmd, char **args, char **path, char **pths, int args_index, int path_index, char **environ)
{
	int rtrn;

	rtrn = exit_check(cmd, args, path, pths, args_index, path_index, environ);
	rtrn = env_check(cmd, args, path, pths, args_index, path_index, environ);

	return (rtrn);
}

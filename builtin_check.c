#include "main.h"

int builtin_check(char **cmd, char **args, char **path, char **pths, int args_index, int path_index, char **environ)
{
	if (exit_check(cmd, args, path, pths, args_index, path_index, environ))
		return (1);
	
	if (env_check(cmd, args, path, pths, args_index, path_index, environ))
		return (1);

	if (setenv_check(cmd, args, path, pths, args_index, path_index, environ))
		return (1);

	return (0);
}

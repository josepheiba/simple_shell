#include "main.h"

int if_command_exist(char *argzero)
{
	if (access(argzero, F_OK) == 0)
		return (1);
	else
		return (0);
}

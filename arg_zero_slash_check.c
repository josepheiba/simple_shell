#include "main.h"

int arg_zero_slash_check(char *argzero)
{
	int i;

	for (i = 0; argzero[i] != '\0'; i++)
	{
		if(argzero[i] == '/' && argzero[i + 1] != '\0')
		{
			return (1);
		}
	}
	return (0);
}

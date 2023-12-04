#include "main.h"

int command_check(char *cmd)
{
	int i;
	char *commands[] = {"exit\n", NULL};

	i = 0;
	while(i < 1 && commands[i] != NULL)
	{
		if(_strcmp(cmd, commands[i]) == 0)
		{
			free(cmd);
			exit(i);
		}
		i++;
	}
	return(0);
}

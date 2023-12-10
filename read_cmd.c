#include "main.h"

int read_cmd(char **cmd, char **args)
{
	size_t len;

	if (_getline(cmd, &len) == -1)
		exit(0);

	/*
	if (command_check(cmd, path, pths, path_index, myenviron) == -1)
		return (-1);
	*/

	return(summon_tokens(*cmd, args));
}

int _getline(char **cmd, size_t *len)
{
	int i, n;
	char *string;
	(void) len;	
	
	string = malloc(sizeof(char) * INT_MAX);
	
	i = 0;
	while (1)
	{
		n = read(0, string + i, 1);
		if (n == 0)
		{
			return (-1);
		}
		else
		{
			if (*(string + i) == '\n')
				break;
		}
		i++;
	}
	*cmd = string;
	return (0);
}

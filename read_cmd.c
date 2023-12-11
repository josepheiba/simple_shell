#include "main.h"

int read_cmd(char **cmd, char **args)
{
	size_t len;

	if (_getline(cmd, &len) == -1)
		exit(status);

	/*
	if (command_check(cmd, path, pths, path_index, myenviron) == -1)
		return (-1);
	*/

	return(summon_tokens(*cmd, args));
}

int _getline(char **cmd, size_t *len)
{
	int i, n;
	char *string, *string2;
	(void) len;
	
	string = malloc(sizeof(char) * 10000000);
	if (string == NULL)
		return (-1);

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
			if (*(string + i) == '\n' || *(string + i) == ';')
			{
				*(string + i + 1) = '\0';
				break;
			}
		}
		i++;
	}

	string2 = malloc(sizeof(char) * (i + 2));
	if (string == NULL)
		return (-1);

	_strcpy(string2, string);
	free(string);

	*cmd = string2;
	return (0);
}

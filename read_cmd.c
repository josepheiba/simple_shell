#include "main.h"

int read_cmd(char **cmd, char **args, int file, int fd)
{
	size_t len;

	if (_getline(cmd, &len, file, fd) == -1)
		exit(status);

	return(summon_tokens(*cmd, args));
}

int _getline(char **cmd, size_t *len, int file, int fd)
{
	int i, n;
	char *string, *string2;
	(void) len;

	if (file == 0)
		fd = 0;

	string = malloc(sizeof(char) * 10000000);
	if (string == NULL)
		return (-1);

	n = i = 0;
	while (1)
	{
		n = read(fd, string + i, 1);
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
	if (string2 == NULL)
		return (-1);

	_strcpy(string2, string);
	free(string);

	*cmd = string2;
	return (0);
}

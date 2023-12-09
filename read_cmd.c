#include "main.h"

int read_cmd(char **cmd, char **args)
{
	size_t len;

	if (getline(cmd, &len, stdin) == -1)
		exit(0);

	/*
	if (command_check(cmd, path, pths, path_index, myenviron) == -1)
		return (-1);
	*/

	return(summon_tokens(*cmd, args));
}

int _getline(char **cmd, size_t *len)
{
	size_t buffer_size;
	ssize_t bytes_read;
	int i;
	char *c = NULL;

	buffer_size = 1;

	i = 0;
	while (1)
	{
		c = realloc(c, (sizeof(char) * (i + 1)));
		if (c == NULL)
			return (0);
		bytes_read = read(STDIN_FILENO, &c[i], buffer_size);
		if (bytes_read == -1)
		{
			free(&c[i]);
			return (-1);
		}
		if (c[i] == '\n')
			break;
		i++;
	}
	*len = i;
	
	*cmd = c;
	return (i);
}

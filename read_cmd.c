#include "main.h"

int read_cmd(char **cmd, char **args, char**path, char **pths, int path_index, char **myenviron)
{
	size_t len;

	getline(cmd, &len, stdin);

	if (command_check(cmd, path, pths, path_index, myenviron) == -1)
		return (-2);

	return(summon_tokens(*cmd, args));
}

int _getline(char **cmd)
{
	int i;
	char *c = (char *)malloc((sizeof(char) * 10000000));
	if (c == NULL)
		return (0);

	for (i = 0; i < 10000000; i++)
		c[i] = '\0';
	
	read(STDIN_FILENO, c, 10000000);
	
	*cmd = c;
	return (0);
}

#include "main.h"

int read_cmd(char **cmd, char **args, char**path, char **pths, int path_index, char **environ)
{
	ssize_t num_chars;
	size_t num;

	num_chars = getline(cmd, &num, stdin);

	if (command_check(cmd, path, pths, path_index, environ) == -1)
		return (-1);

	return(summon_tokens(*cmd, args, num_chars));
}

int _getline(char **cmd)
{
	char *c = (char *)malloc((sizeof(char) * 10000000));
	
	read(STDIN_FILENO, c, 10000000);
	*cmd = malloc(sizeof(char) * (_strlen_recursion(c) + 1));
	_strcpy(*cmd, c);

	free(c);
	return (0);
}

#include "main.h"

int read_cmd(char **cmd, char **args, char**path, char **pths, int path_index)
{
	ssize_t num_chars;
	size_t len = 0;

	num_chars = getline(cmd, &len, stdin);

	command_check(cmd, path, pths, path_index);
	
	return(summon_tokens(*cmd, args, num_chars));
}

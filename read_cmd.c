#include "main.h"

int read_cmd(char *cmd, char **args)
{
	ssize_t num_chars;
	size_t len = 0;

	if ((num_chars = getline(&cmd, &len, stdin)) == -1)
		return(-1);

	return(summon_tokens(cmd, args, num_chars));
}

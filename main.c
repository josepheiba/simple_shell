#include "main.h"

int main(void)
{
	char *cmd;
	char **args;
	int process_id;
	int free_index;
	
	(void) free_index;
	cmd = malloc(0);
	args = malloc(0);

	while (1)
	{
		init_prompt();
		read_cmd(cmd, args);

		process_id = fork();
		if (process_id == 0)
		{
			execve(args[0], args, NULL);
		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
}

#include "main.h"

int main(void)
{
	char *cmd;
	char *args[512];
	int process_id;
	int free_index;

	extern char **environ;

	while (1)
	{
		cmd = NULL;
		init_prompt();
		free_index = read_cmd(&cmd, args);

		process_id = fork();
		if (process_id != 0)
		{
			wait(NULL);
			free_cmd_args(&cmd, args, free_index);
		}
		else
		{
			execve(args[0], args, environ);
		}
	}
	return (0);
}

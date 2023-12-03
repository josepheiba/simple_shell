#include "main.h"

int main(void)
{
	char *cmd;
	char **args;
	int process_id;
	int free_index;
	int status;
	char *argv[] = {"/bin/ls", "-l", "-a", NULL};
	
	cmd = malloc(0);
	args = malloc(0);

	while (1)
	{
		init_prompt();
		free_index = read_cmd(cmd, args);

		process_id = fork();
		if (process_id == 0)
		{
			printf("%s %s %s %s\n", argv[0], argv[1], argv[2], argv[3]);
			printf("%s %s %s %s\n", args[0], args[1], args[2], args[3]);
			execve(args[0], args, NULL);
			free_cmd_args(cmd, args, free_index);
			return (0);
		}
		else
		{
			wait(&status);
		}
	}
	free_cmd_args(cmd, args, free_index);
	return (0);
}

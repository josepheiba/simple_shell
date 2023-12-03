#include "main.h"

int main(void)
{
	char *cmd;
	char *args[100];
	int process_id;
	int free_index;
	
	(void) free_index;

	while (1)
	{
		init_prompt();
		read_cmd(*&cmd, args);

		process_id = fork();
		if (process_id != 0)
			wait(NULL);
		else
		{
			execve(args[0], args, NULL);
		}
	}
	return (0);
}

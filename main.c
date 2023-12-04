#include "main.h"

int main(void)
{
	char *cmd;
	char *args[512];
	char *path;
	char *pths[512];
	int process_id;
	int args_index;
	int path_index, true_path_index;
	extern char **environ;
	char *tmp;

	path = NULL;
	pathfinder(&path, environ);
	path_index = token_paths(path, pths);

	while (1)
	{
		cmd = NULL;
		init_prompt();
		args_index = read_cmd(&cmd, args, &path, pths, path_index);

		if (arg_zero_slash_check(args[0]))
		{
			if (!if_command_exist(args[0]))
			{
				free_cmd_args(&cmd, args, args_index);
				continue;
			}
		}
		else
		{
			if (!(true_path_index = if_path_command_exist(pths, args[0])))
			{
				free_cmd_args(&cmd, args, args_index);
				continue;
			}
			else
			{
				tmp = str_concat(pths[true_path_index], args[0]);
				args[0] = realloc(args[0], sizeof(char) * (_strlen_recursion(tmp) + 1));
				_strcpy(args[0], tmp);
				free(tmp);
			}
		}

		process_id = fork();
		if (process_id != 0)
		{
			wait(NULL);
			free_cmd_args(&cmd, args, args_index);
		}
		else
		{
			execve(args[0], args, environ);
		}
	}
	return (0);
}

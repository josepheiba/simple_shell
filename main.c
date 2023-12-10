#include "main.h"

int main(void)
{
	char *cmd, *path, *tmp, *args[512], *pths[512], *myenviron[512];
	int process_id, args_index, path_index, true_path_index, status;

	environcpy(myenviron);
	path = args[0] = NULL;
	pathfinder(&path, environ);
        if (path != NULL)
	        path_index = token_paths(path, pths);
	while (1)
	{
		cmd = NULL;
		init_prompt();
		args_index = read_cmd(&cmd, args);
		
		if (args[0] == NULL)
		{
			free(cmd);
			continue;
		}
		if (builtin_check(&cmd, args, &path, pths, args_index, path_index, myenviron))
		{
			free_cmd_args(&cmd, args, args_index);
			continue;
		}
		if (arg_zero_slash_check(args[0]))
		{
			if (!if_command_exist(args[0]))
			{
				free_cmd_args(&cmd, args, args_index);
				continue;
			}
		}
		else if (path == NULL)
		{
			not_found(args[0], &cmd, args, &path, pths, path_index);
			continue;
		}
		else
		{
			if (!(true_path_index = if_path_command_exist(pths, args[0])))
			{
				if (pths[0] == NULL || 1)
					not_found(args[0], &cmd, args, &path, pths, path_index);
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
			wait(&status);
			free_cmd_args(&cmd, args, args_index);
			error_check(status);
		}
		else
		{
			execve(args[0], args, environ);
		}
	}
	return (0);
}

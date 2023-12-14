#include "main.h"

/**
 * main - check code.
 * @argc: variable
 * @argv: variable
 * Return: check declaration
 */


int main(int argc, char **argv)
{
	char *cmd, *path, *tmp, *args[512], *pths[512], *myenviron[512];
	int process_id, args_index, path_index, true_path_index, file, fd;

	file = argc - 1;
	if (file == 1)
	{
		fd = open(argv[file], O_RDONLY);
		if (fd == -1)
			status = 127;
	}

	environcpy(myenviron);
	path = args[0] = NULL;
	pathfinder(&path, environ);

	if (path != NULL)
	{
		path_index = token_paths(path, pths);
		if (path_index == -1)
		{
			exit(status);
		}
	}

	while (1)
	{
		cmd = NULL;
		args_index = read_cmd(&cmd, args, &path, pths, path_index, myenviron, file, fd, argv[file]);
		if (args_index < 0)
		{
			free(cmd);
			continue;
		}

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
		status = 0;
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
			true_path_index = if_path_command_exist(pths, args[0]);
			if (true_path_index <= 0)
			{
				if (pths[0] == NULL || 1)
					not_found(args[0], &cmd, args, &path, pths, path_index);
				free_cmd_args(&cmd, args, args_index);
				continue;
			}
			else
			{
				tmp = str_concat(pths[true_path_index], args[0]);
				if (tmp == NULL)
				{
					free_cmd_args(&cmd, args, args_index);
					continue;
				}
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
			error_check();
		}
		else
		{
			execve(args[0], args, environ);
		}
	}
	return (status);
}

#include "main.h"

int read_cmd(char **cmd, char **args, char **path, char **pths, int path_index, char **myenviron, int file, int fd, char *argvone)
{
	int j, l;
	size_t len;
	(void) file;
	(void) fd;
	(void) argvone;
	(void) pths;
	(void) path;
	(void) path_index;
	(void) args;
	(void) myenviron;
	(void) j;
	(void) l;

	/*
	if (getline(cmd, &len, stdin) == -1)
		*/

	if (_getline(cmd, &len, file, fd, argvone) == -1)
	{
		for (j = 0; j < path_index; j++)
			free(pths[j]);
		free(*path);

		for (l = 0; myenviron[l] != NULL; l++)
			free(myenviron[l]);
		exit(status);
	}

	return(summon_tokens(*cmd, args));
}

int dollar_replace(char **cmd)
{
	int i, j;
	char *token;
	char *token2;
	char *number;
	char option;
	char *final_cmd12;
	char *final_cmd22;
	pid_t ppiidd;

	j = 0;
	while (1)
	{
		if (cmd[0][j] == '$')
			break;
		if (cmd[0][j] == '\n' || cmd[0][j] == ';')
			return (0);
		j++;
	}

	token = strtok(*cmd, "$");
	i = _strlen_recursion(token);

	option = cmd[0][i + 1]; 
	cmd[0][i + 1] = '$';

	token2 = strtok(NULL, "$");

	if (option == '?')
		number = _itoa(status);
	else if (option == '$')
	{
		ppiidd = getpid();
		number = _itoa(ppiidd);
	}
	else
		return(0);

	final_cmd12 = str_concat(token, number);
	final_cmd22 = str_concat(final_cmd12, token2);

	free(*cmd);
	free(number);

	free(final_cmd12);
	*cmd = final_cmd22;
	return(0);
}

char *_itoa(int number)
{
	int i, n;
	char *string = malloc(sizeof(char) * 10);
	if (string == NULL)
		return(NULL);

	if (number == 0)
	{
		*(string + 0) = '0';
		*(string + 1) = '\0';
		return (string);
	}

	i = 0;
	while(number >= 1)
	{
		n = number % 10;
		*(string + i) = n + '0';
		number = number / 10;
		i++;
	}
	*(string + i) = '\0';
	rev_string(string);
	return (string);
}

int _getline(char **cmd, size_t *len, int file, int fd, char *argvone)
{
	int i, n;
	char *string, *string2;
        char *error_start = "./hsh: 0: Can't open ";
        char *error_end = "\n";
	(void) len;

	if (file == 0)
		fd = 0;
	else if (file == 1 && status == 127)
	{
		write(STDERR_FILENO, error_start, _strlen_recursion(error_start));
		write(STDERR_FILENO, argvone, _strlen_recursion(argvone));
		write(STDERR_FILENO, error_end, _strlen_recursion(error_end));
		return (-1);
	}

	string = malloc(sizeof(char) * 10000000);
	if (string == NULL)
		return (-1);

	n = i = 0;
	while (1)
	{
		n = read(fd, string + i, 1);
		if (n == 0)
		{
			free(string);
			return (-1);
		}
		else
		{
			if (*(string + i) == '\n' || *(string + i) == ';')
			{
				*(string + i + 1) = '\0';
				break;
			}
		}
		i++;
	}

	string2 = malloc(sizeof(char) * (i + 2));
	if (string2 == NULL)
		return (-1);

	_strcpy(string2, string);
	free(string);

	*cmd = string2;
	return (0);
}

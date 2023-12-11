#include "main.h"

int read_cmd(char **cmd, char **args, int file, int fd, char *argvone)
{
	size_t len;

	if (_getline(cmd, &len, file, fd, argvone) == -1)
		exit(status);

	return(summon_tokens(*cmd, args));
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

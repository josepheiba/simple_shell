#include "main.h"

int pathfinder(char **path, char **environ)
{
	char *patheq = "PATH=";
	int i, j;

	i = 0;
	while (environ[i] != NULL)
	{
		j = 0;
		while (environ[i][j] != '\0')
		{
			if (environ[i][j] != patheq[j])
				break;
			j++;
			if (patheq[j] == '\0')
			{
				*path = malloc(sizeof(char) * (_strlen_recursion(environ[i]) + 1));
				_strcpy(*path, environ[i]);
				return (0);
			}
		}
		i++;
	}
	return (-1);
}

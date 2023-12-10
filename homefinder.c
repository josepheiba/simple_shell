#include "main.h"

int homefinder(char **home, char **environ)
{
	char *patheq = "HOME=";
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
				*home = malloc(sizeof(char) * (_strlen_recursion(environ[i]) + 1));
				_strcpy(*home, environ[i]);
				return (0);
			}
		}
		i++;
	}
	return (-1);
}

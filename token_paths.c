#include "main.h"

int token_paths(char *path, char **pths)
{
	char *token;
	int i, j;

	i = 0;
	token = strtok(path, "=:");
	while ((token = strtok(NULL, "=:")) != NULL)
	{
		pths[i] = malloc(sizeof(char) * (_strlen_recursion(token) + 2));
		if (pths[i] == NULL)
			return(-1);
		_strcpy(pths[i], token);
		j = 0;
		while (pths[i][j] != '\0')
			j++;
		pths[i][j + 1] = pths[i][j];
		pths[i][j] = '/';
		i++;
	}
		pths[i] = NULL;
	return (i);
}

#include "main.h"

int oldpwdfinder(char **oldpwd, int *oldpwdindex, char **myenviron)
{
	char *patheq = "OLDPWD=";
	int i, j;

	i = 0;
	while (myenviron[i] != NULL)
	{
		j = 0;
		while (myenviron[i][j] != '\0')
		{
			if (myenviron[i][j] != patheq[j])
				break;
			j++;
			if (patheq[j] == '\0')
			{
				*oldpwd = malloc(sizeof(char) * (_strlen_recursion(myenviron[i]) + 1));
				_strcpy(*oldpwd, myenviron[i]);
				*oldpwdindex = i;
				return (0);
			}
		}
		i++;
	}
	return (-1);
}

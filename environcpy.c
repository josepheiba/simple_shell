#include "main.h"

/**
 * environcpy - check code.
 * myenviron : variable
 * Return: check declaration
 */

void environcpy(char **myenviron)
{
	int i, k;

	i = 0;
	while (environ[i] != NULL)
	{
		myenviron[i] = malloc(sizeof(char) * (_strlen_recursion(environ[i]) + 1));
		if (myenviron[i] == NULL)
		{
			for (k = 0; k < i; k++)
				free(myenviron[k]);
			exit(0);
		}
		_strcpy(myenviron[i], environ[i]);
		i++;
	}
	myenviron[i] = NULL;
}




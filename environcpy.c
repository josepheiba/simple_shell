#include "main.h"

void environcpy(char **myenviron)
{
	int i;

	i = 0;
	while (environ[i] != NULL)
	{
		myenviron[i] = malloc(sizeof(char) * (_strlen_recursion(environ[i]) + 1));
		if (myenviron[i] == NULL)
			_exit(1);
		_strcpy(myenviron[i], environ[i]);
		i++;
	}
	myenviron[i] = NULL;
}




#include "main.h"

int write_oldcwd(char *cwd, int oldpwdindex, char **myenviron)
{
	char *temp;
	char *stringlinteral = "OLDPWD=";

	temp = str_concat(stringlinteral, cwd);

	free(myenviron[oldpwdindex]);

	myenviron[oldpwdindex] = malloc(sizeof(char) * _strlen_recursion(cwd) + 7 + 1);

	_strcpy(myenviron[oldpwdindex], temp);

	free(temp);
	return (0);
}

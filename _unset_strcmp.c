#include "main.h"

/**
 * _strcmp - check code
 * @s1: input
 * @s2: input
 * Return: check function declaration
 */

int _unset_strcmp(char *s1, char *s2)
{
	int i, diff;

	i = diff = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] != '=' && s2[i] != '=')
	{
		diff = s1[i] - s2[i];
		if (diff != 0)
			break;
	i++;
	}
	return (diff);
}

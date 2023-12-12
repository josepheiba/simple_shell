#include "main.h"

/**
 * rev_string - check code
 * @s: input
 * Return: check function declaration
 */

void rev_string(char *s)
{
	int i, j;
	char c;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (j < i / 2)
	{
		c = s[j];
		s[j] = s[i - j - 1];
		s[i - j - 1] = c;
		j++;
	}
}

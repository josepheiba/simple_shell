#include "main.h"

/**
 * *_strcpy - check code
 * @dest: input
 * @src: input
 * Return: check function declaration
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		*(dest + i) = *(src + i);
	i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

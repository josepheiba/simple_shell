#include "main.h"

/**
 * error_check - check code.
 * Return: check declaration
 */

int error_check(void)
{
	if(status == 512)
	{
		status = 2;
		return(-1);
	}
	return(0);
}

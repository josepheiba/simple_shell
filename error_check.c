#include "main.h"

int error_check(void)
{
	if(status == 512)
	{
		status = 2;
		return(-1);
	}
	return(0);
}

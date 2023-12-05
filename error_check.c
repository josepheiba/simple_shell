#include "main.h"

int error_check(int status)
{
	if(status == 512)
	{
		_exit(2);
		return(-1);
	}
	return(0);
}

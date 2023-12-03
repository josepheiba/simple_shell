#include "main.h"

int init_prompt(void)
{
	char *prompt_text = "$ ";

	if (write(1, prompt_text, 3) != -1)
		return (0);
	return(-1);
}


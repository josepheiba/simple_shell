#include "main.h"

int init_prompt(void)
{
	char *prompt_text = "";

	if (write(1, prompt_text, _strlen_recursion(prompt_text)) != -1)
		return (0);
	return(-1);
}


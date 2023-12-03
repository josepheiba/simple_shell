#include "main.h"

int main(void)
{
	size_t n = 0;
	char *string;
	char *token;
	ssize_t read;
	char *bruh[] = {"/bin/git", "commit", "-m", "ok", NULL};
	printf("$ ");
	read = getline(&string, &n, stdin);
	if (read != -1)
	{
		token = strtok(string, " ");
		while((token = strtok(NULL, " ")) != NULL)
			printf("%s\n", token);
	}
	execve(bruh[0], bruh, NULL);
	return (0);
}

#include "main.h"

/**
 * cd_check - check code.
 * cmd : variable
 * path : variable
 * path : variable
 * pths : variable
 * args_index : variable
 * path_index : variable
 * myenviron : variable
 * Return: check declaration
 */

int cd_check(char **cmd, char **args, char **path, char **pths, int args_index, int path_index, char **myenviron)
{
	int i, oldpwdindex;
	char *commands[] = {"cd\n", NULL};
	char *homepath = NULL;
	char *oldpwdpath = NULL;
	char *home = NULL;
	char *oldpwd = NULL;
	char *dash = "-";
	char *end = "\n";
	char cwd[1024];
	(void) cmd;
	(void) path;
	(void) pths;
	(void) args_index;
	(void) path_index;

	getcwd(cwd, sizeof(cwd));

	homefinder(&home, myenviron);
	homepath = strtok(home, "HOME=");

	i = 0;
	while(commands[i] != NULL)
	{
		if (_strcmp(args[0], commands[i]) == 0)
		{
			
			if (oldpwdfinder(&oldpwd, &oldpwdindex, myenviron) != -1)
			{
				oldpwdpath = strtok(oldpwd, "OLDPWD=");
				write_oldcwd(cwd, oldpwdindex, myenviron);
			}
			else
			{
				write(STDOUT_FILENO, cwd, _strlen_recursion(cwd));
				write(STDOUT_FILENO, end, _strlen_recursion(end));
				return (1);
			}

			if (args[1] != NULL && _strcmp(args[1], dash) == 0)
			{
				
				chdir(oldpwdpath);
				free(home);
				free(oldpwd);
				return (1);
			
			}
			else if (args[1] != NULL)
			{
				if (chdir(args[1]) == -1)
					cant_cd(args[1]);
				free(home);
				free(oldpwd);
				return (1);
			}
			else
			{
				chdir(homepath);
				free(home);
				free(oldpwd);
				return (1);
			}
		}
		i++;
	}
	free(home);
	return(0);
}

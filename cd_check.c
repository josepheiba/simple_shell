#include "main.h"

int cd_check(char **cmd, char **args, char **path, char **pths, int args_index, int path_index, char **myenviron)
{
	int i, oldpwdindex;
	size_t cwdlen = 0;
	char *commands[] = {"cd\n", NULL};
	char *homepath = NULL;
	char *oldpwdpath = NULL;
	char *home = NULL;
	char *oldpwd = NULL;
	char *dash = "-";
	char *cwd = NULL;
	(void) cmd;
	(void) path;
	(void) pths;
	(void) args_index;
	(void) path_index;

	cwd = getcwd(cwd, cwdlen);

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
			if (args[1] != NULL && _strcmp(args[1], dash) == 0)
			{
				
				chdir(oldpwdpath);
				free(home);
				free(oldpwd);
				return (1);
			
			}
			else if (args[1] != NULL)
			{
				chdir(args[1]);
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

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <limits.h>
#include <elf.h>
#include <fcntl.h>

int status;

extern char **environ;

void environcpy(char **myenviron);

int init_prompt(void);
int read_cmd(char **cmd, char **args, int file, int fd);
int command_check(char **cmd, char **path, char **pths, int path_index, char **myenviron);
int free_cmd_args(char **cmd, char **args, int free_index);
int pathfinder(char **path, char **environ);
int homefinder(char **home, char **environ);
int oldpwdfinder(char **oldpwd, int *oldpwdindex, char **environ);
int token_paths(char *path, char **pths);
int arg_zero_slash_check(char *argzero);
int if_command_exist(char *argzero);
int if_path_command_exist(char **pths, char *argzero);
int not_found(char *argzero, char **cmd, char **args, char **path, char **pths, int path_index);
int error_check(void);
int cant_cd(char *foldername);
int _getline(char **cmd, size_t *len, int file, int fd);
int summon_tokens(char *cmd, char **args);
int exit_check(char **cmd, char **args, char **path, char **pths, int args_index, int path_index, char **myenviron);
int env_check(char **cmd, char **args, char **path, char **pths, int args_index, int path_index, char **myenviron);
int cd_check(char **cmd, char **args, char **path, char **pths, int args_index, int path_index, char **myenviron);
int setenv_check(char **cmd, char **args, char **path, char **pths, int args_index, int path_index, char **myenviron);
int unsetenv_check(char **cmd, char **args, char **path, char **pths, int args_index, int path_index, char **myenviron);
int builtin_check(char **cmd, char **args, char **path, char **pths, int args_index, int path_index, char **myenviron);
int write_oldcwd(char *cwd, int oldpwdindex, char **myenviron);

char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _unset_strcmp(char *s1, char *s2);
int _strlen_recursion(char *s);
char *str_concat(char *s1, char *s2);
int _atoi(char *s);

#endif

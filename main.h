#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

int init_prompt(void);
int read_cmd(char **cmd, char **args);
int summon_tokens(char *cmd, char **args, int num_chars);
int free_cmd_args(char **cmd, char **args, int free_index);
int command_check(char *cmd);

char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen_recursion(char *s);

#endif

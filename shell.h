#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

/* Function prototypes */
char **split_line(char *line);
void execute_command(char **args);
char *find_path(char *command);
void copy_file(const char *src, const char *dest);

#endif

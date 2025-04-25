#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

/* Function prototypes */
void execute_command(char **args);
char *search_in_path(char *command);
void copy_file(const char *src, const char *dest);
char **split_line(char *line);
extern char **environ;

#endif

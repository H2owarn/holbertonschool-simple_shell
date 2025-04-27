#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    char **args;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "($) ", 4);

        nread = getline(&line, &len, stdin);
        if (nread == -1)
        {
            free(line);
            exit(EXIT_SUCCESS);
        }

        args = split_line(line);
        if (args == NULL)
            continue;

        if (_strcmp(args[0], "exit") == 0)
        {
            free_args(args);
            free(line);
            exit(EXIT_SUCCESS);
        }

        execute_command(args);
        free_args(args);
    }

    free(line);
    return 0;
}


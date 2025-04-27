#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    char **args;

    while (1)
    {
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "$ ", 2);

        nread = getline(&line, &len, stdin);
        if (nread == -1)
        {
            free(line);
            exit(EXIT_SUCCESS);
        }

        args = parse_line(line);
        if (args == NULL)
            continue; // If parsing fails, skip.

        if (_strcmp(args[0], "exit") == 0)
            handle_exit(args);

        execute_command(args);
        free_args(args); // Free allocated memory for args.
    }

    free(line);
    return 0;
}

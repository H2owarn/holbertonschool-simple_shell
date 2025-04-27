#include "shell.h"

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
        if (args[0] != NULL && _strcmp(args[0], "exit") == 0)
	{
		handle_exit(args);
	}
	else
	{
            execute_command(args);
	}
        free(args);
    }
    free(line);
    return 0;
}

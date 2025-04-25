#include "shell.h"
#include "sys/stat.h"
#include "unistd.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
char *find_path(char *command)
{
    struct stat st;

    if (stat(command, &st) == 0 && (st.st_mode & S_IXUSR))
        return strdup(command); /* Return a copy of the command if valid */

    /* Search in PATH if command is not an absolute/relative path */
    return search_in_path(command);
}

void execute_command(char **args)
{
    char *path = find_path(args[0]);
    pid_t pid;
    int status;

    if (!path)
    {
        write(STDERR_FILENO, args[0], strlen(args[0]));
        write(STDERR_FILENO, ": Command not found\n", 20);
        return;
    }

    pid = fork();
    if (pid == -1)
    {
        perror("Fork failed");
        free(path);
        return;
    }

    if (pid == 0) /* Child process */
    {
        if (execve(path, args, environ) == -1)
        {
            perror(args[0]);
            free(path);
            exit(EXIT_FAILURE);
        }
    }
    else /* Parent process */
    {
        wait(&status);
        free(path);
    }
}

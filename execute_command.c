#include "shell.h"
#include "sys/stat.h"
#include "unistd.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
/**
 *
 *
 */
char *find_path(char *command)
{
    struct stat st;
    char *path_env = NULL, *dir, *full_path;
    int i;

    /* Check PATH in environ */
    for (i = 0; environ[i]; i++)
    {
        if (strncmp(environ[i], "PATH=", 5) == 0)
        {
            path_env = environ[i] + 5; /* Skip "PATH=" */
            break;
        }
    }

    /* If PATH is empty, rely only on absolute paths */
    if (!path_env || strlen(path_env) == 0)
    {
        if (stat(command, &st) == 0 && (st.st_mode & S_IXUSR))
            return strdup(command);
        return NULL;
    }

    /* Search command in PATH directories */
    dir = strtok(path_env, ":");
    while (dir)
    {
        full_path = malloc(strlen(dir) + strlen(command) + 2);
        if (!full_path)
        {
            perror("Error allocating memory");
            return NULL;
        }
        sprintf(full_path, "%s/%s", dir, command);
        if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
            return full_path;
        free(full_path);
        dir = strtok(NULL, ":");
    }

    return NULL;
}
/**
 *
 *
 */
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

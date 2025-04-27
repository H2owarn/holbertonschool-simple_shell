#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

char *find_path(char *command)
{
    char *path_env, *path_copy, *dir;
    char *full_path;
    size_t full_len;

    if (!command)
        return NULL;

    /* Get PATH from the environment */
    path_env = getenv("PATH");
    if (!path_env)
        return NULL;

    /* Make a copy because strtok modifies the string */
    path_copy = strdup(path_env);
    if (!path_copy)
        return NULL;

    dir = strtok(path_copy, ":");
    while (dir != NULL)
    {
        /* Build full path string: dir + "/" + command + null */
        full_len = strlen(dir) + 1 + strlen(command) + 1;
        full_path = malloc(full_len);
        if (!full_path)
        {
            free(path_copy);
            return NULL;
        }

        strcpy(full_path, dir);
        strcat(full_path, "/");
        strcat(full_path, command);

        /* Check if this file exists and is executable */
        if (access(full_path, X_OK) == 0)
        {
            free(path_copy);
            return full_path; /* SUCCESS: Return this path */
        }

        /* Otherwise try next directory */
        free(full_path);
        dir = strtok(NULL, ":");
    }

    /* Not found */
    free(path_copy);
    return NULL;
}
/**
 *
 */
{
    char *path = NULL;
    pid_t pid;
    int status;

    if (!args || !args[0]) /* Always validate inputs */
        return;

    /* Check if the command contains a '/' */
    if (strchr(args[0], '/'))
    {
        path = args[0];
    }
    else
    {
        /* Otherwise, search in PATH */
        path = find_path(args[0]);
        if (!path)
        {
            write(STDERR_FILENO, args[0], strlen(args[0]));
            write(STDERR_FILENO, ": Command not found\n", 20);
            return;
        }
    }

    /* Always fork for executing commands */
    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        if (path != args[0]) /* Free only if it was dynamically allocated */
            free(path);
        return;
    }

    if (pid == 0)
    {
        /* Child process */
        if (execve(path, args, environ) == -1)
        {
            perror(args[0]);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        /* Parent process */
        wait(&status);
    }

    /* Free path if we malloc'd it */
    if (path != args[0])
        free(path);
}

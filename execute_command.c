#include "shell.h"

char *find_path(char *command)
{
    char *path = getenv("PATH");
    char *dir, *full_path;
    struct stat st;

    if (!path)
        return NULL;

    dir = strtok(path, ":");
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

void execute_command(char **args)
{
    char *path = NULL;
    pid_t pid;
    int status;

    if (args[0][0] == '/')
        path = args[0];
    else
        path = find_path(args[0]);

    if (!path)
    {
        write(STDERR_FILENO, args[0], strlen(args[0]));
        write(STDERR_FILENO, ": Command not found\n", 20);
        return;
    }

    pid = fork();
    if (pid == -1)
    {
        perror(args[0]);
        free(path);
        return;
    }
    if (pid == 0)
    {
        if (execve(path, args, environ) == -1)
        {
            perror(args[0]);
            exit(EXIT_FAILURE);
        }
    }
    else
        wait(&status);

    if (args[0][0] != '/')
        free(path);
}

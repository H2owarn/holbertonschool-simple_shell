#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char *search_in_path(char *command)
{
    char *path = NULL, *dir, *full_path;
    struct stat st;
    int i = 0;
    extern char **environ;

    /* Locate PATH in the environ array */
    while (environ[i])
    {
        if (strncmp(environ[i], "PATH=", 5) == 0)
        {
            path = environ[i] + 5; /* Skip "PATH=" to get the actual value */
            break;
        }
        i++;
    }

    if (!path)
        return NULL;

    /* Split PATH into directories and search for the command */
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

#include "shell.h"

char *search_in_path(char *command)
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

    /* Handle empty PATH */
    if (!path_env || strlen(path_env) == 0)
    {
        if (stat(command, &st) == 0 && (st.st_mode & S_IXUSR))
            return strdup(command);
        return NULL;
    }

    /* Search for command in PATH directories */
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

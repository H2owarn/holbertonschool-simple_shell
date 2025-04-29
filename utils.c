#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

/**
 * get_path_env - Retrieve the value of the
 * PATH environment variable
 * Return: value of the PATH environment variable
 * (without the "PATH=" prefix),
 * or NULL if the "PATH" entry is not found.
 */
char *get_path_env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			/* Skip "PATH=" and return the value */
			return (environ[i] + 5);
		}
	}
	return (NULL); /* PATH not found */
}

#include "shell.h"

/**
 * find_path - finds the full path of a command
 * @command: the command to search
 * Return: full path or NULL
 */
char *find_path(char *command)
{
    char *path_env, *path_copy, *dir;
    char *full_path;
    int i;
    struct stat st;

    for (i = 0; environ[i]; i++)
    {
        if (_strncmp(environ[i], "PATH=", 5) == 0)
        {
            path_env = environ[i] + 5;
            break;
        }
    }

    if (!environ[i])
        return NULL;

    if (!path_env || *path_env == '\0')
        return NULL;

    path_copy = _strdup(path_env);
    dir = _strtok(path_copy, ":");

    while (dir)
    {
        full_path = malloc(_strlen(dir) + _strlen(command) + 2);
        if (!full_path)
        {
            free(path_copy);
            return NULL;
        }

        _strcpy(full_path, dir);
        _strcat(full_path, "/");
        _strcat(full_path, command);

        if (stat(full_path, &st) == 0)
        {
            free(path_copy);
            return full_path;
        }

        free(full_path);
        dir = _strtok(NULL, ":");
    }

    free(path_copy);
    return NULL;
}

/**
 * get_command_path - Find the full path of a command
 * @args: Null-terminated array of arguments passed to the shell
 * Return: A string containing the full path to the command
**/
char *get_command_path(char **args)
{
	char *path = NULL;

	if (_strchr(args[0], '/'))
	{
		path = _strdup(args[0]);
	}
	else
	{
		path = find_path(args[0]);
	}
	return (path);
}

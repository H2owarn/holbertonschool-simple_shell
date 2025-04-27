#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "shell.h"
/**
 *
*/

extern char **environ; /* Declare the global environment variable */

char *find_path(char *command)
{
    char *path = NULL, *dir, *full_path;
    struct stat st;
    int i = 0;

    /* Search for PATH in the environ array */
    while (environ[i])
    {
        if (strncmp(environ[i], "PATH=", 5) == 0)
        {
            path = environ[i] + 5; /* Skip "PATH=" */
            break;
        }
        i++;
    }

    if (!path || strcmp(path, "") == 0)
    {
        /* Fallback to /bin if PATH is empty */
        path = "/bin";
    }

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
        {
            return full_path; /* Command found */
        }

        free(full_path);
        dir = strtok(NULL, ":");
    }

    return NULL; /* Command not found */
}
/**
 *
 */
#include "shell.h"

/**
 * execute_command - Search, fork and execute a command
 * @args: Arguments (array of strings)
 * Return: 1 to continue shell loop, 0 to exit
 */
int execute_command(char **args)
{
	pid_t pid;
	int status;
	char *command_path;

	if (args[0] == NULL)
		return (1);

	/* Search if the command exists */
	command_path = search_in_path(args[0]);
	if (command_path == NULL)
	{
		/* Check if it's an absolute or relative path */
		if (access(args[0], X_OK) == 0)
		{
			command_path = strdup(args[0]);
			if (command_path == NULL)
			{
				perror("simple_shell");
				return (1);
			}
		}
		else
		{
			dprintf(STDERR_FILENO, "simple_shell: %s: not found\n", args[0]);
			return (1);
		}
	}

	/* Fork only if executable found */
	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		if (execve(command_path, args, environ) == -1)
		{
			perror("simple_shell");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		/* Fork error */
		perror("simple_shell");
	}
	else
	{
		/* Parent process */
		waitpid(pid, &status, 0);
	}

	free(command_path);
	return (1);
}

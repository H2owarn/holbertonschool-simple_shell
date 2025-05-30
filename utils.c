#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
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

/**
 * find_path - Search for a command in directories listed
 * in the PATH environment variable
 * @command: The command name to search for.
 * Return: The full path of the executable,
 * NULL if the command is not found or is not executable.
 */
char *find_path(char *command)
{
	char *path_env = get_path_env();
	char *token, *path_copy, *full_path;
	struct stat st;

	path_copy = _strdup(path_env);
	token = strtok(path_copy, ":");
	while (token)
	{
		full_path = malloc(_strlen(token) + _strlen(command) + 2);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, command);
		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
/**
 * get_command_path - Find the full path of a command
 * @args: Null-terminated array of arguments passed to the shell
 * Return: A string containing the full path to the command
 */
char *get_command_path(char **args)
{
	char *path_env, *path = NULL;

	if (_strchr(args[0], '/'))
		return (_strdup(args[0]));
	path_env = get_path_env();
	if (!path_env || path_env[0] == '\0')
		return (NULL);

	path = find_path_custom(args[0], path_env);
	return (path);
}
/**
 * find_path_custom - Search for a command in a given PATH string
 * @command: The command name (e.g., "ls")
 * @path_env: The PATH environment string (e.g., "bin:/usr/bin")
 * Return: Full path to the command if found, or NULL if not found
 */
char *find_path_custom(char *command, char *path_env)
{
	char *path_copy, *dir, *full_path;
	struct stat st;

	if (!command || !path_env)
		return (NULL);
	path_copy = _strdup(path_env);
	if (!path_copy)
		return (NULL);
	dir = strtok(path_copy, ":");
	while (dir)
	{
		full_path = malloc(_strlen(dir) + _strlen(command) + 2);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}
		strcpy(full_path, dir);
		strcat(full_path, "/");
		strcat(full_path, command);
		if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
/**
 * handle_builtin_exit - Handle the 'exit' built-in command
 * @args: Null-terminated array of arguments passed to the shell
* Return: 1 if 'exit' command is executed, 0 otherwise
 */
int handle_builtin_exit(char **args)
{
	if (_strcmp(args[0], "exit") == 0)
	{
		free_args(args);
		exit(last_exit_status);
	}
	return (0);
}
/**
 * handle_builtin_env - Handle the 'env' built-in command
 * @args: Null-terminated array of arguments passed to the shell
* Return: 1 if 'exit' command is executed, 0 otherwise
 */
int handle_builtin_env(char **args)
{
	int i;

	if (_strcmp(args[0], "env") == 0)
	{
		for (i = 0; environ[i]; i++)
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
		last_exit_status = 0;
		return (1);
	}
	return (0);
}
/**
 * execute_fork - Fork the process and execute a command
 * @path: Full path to the command to be executed
 * @args: Null-terminated array of arguments passed to the shell
 * Return: The status code of the executed command.
 */
int execute_fork(char *path, char **args)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("Error:");
		free(path);
		return (-1);
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
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			last_exit_status = WEXITSTATUS(status);
		}
		else if (WIFSIGNALED(status))
		{
			last_exit_status = 128 + WTERMSIG(status);
		}
		else
		{
			last_exit_status = 1;
		}
	}
	return (0);
}
/**
 * execute_command - Execute a command in a new process
 * @args: Null-terminated array of arguments passed to the shell
 **/
void execute_command(char **args)
{
	char *path = NULL;

	if (!args || !args[0])
		return;
	if (handle_builtin_exit(args))
		return;
	if (handle_builtin_env(args))
		return;
	path = get_command_path(args);
	if (!path)
	{
		write(STDERR_FILENO, "./hsh: 1: ", 10);
		write(STDERR_FILENO, args[0], _strlen(args[0]));
		write(STDERR_FILENO, ": not found\n", 12);
		last_exit_status = 127;
		if (!isatty(STDIN_FILENO))
		{
			free_args(args);
			exit(last_exit_status);
		}
		return;
	}
	execute_fork(path, args);
	free(path);
}

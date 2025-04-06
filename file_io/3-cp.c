#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include "main.h"
#define BUFFER_SIZE 1024
/**
 * main - Copies the content of a file to another file.
 * @argc: The number of arguments.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the number of arguments is not exactly 3, exit with code 97
 * and print "Usage: cp file_from file_to" on the POSIX standard error. If
 * file_from does not exist or cannot be read, exit with code 98 and print
 * "Error: Can't read from file NAME_OF_THE_FILE". If file_to cannot be created
 * or written to, exit with code 99 and print "Error: Can't write to NAME_OF_THE_FILE".
 * If a file descriptor cannot be closed, exit with code 100 and print "Error: Can't close fd FD_VALUE".
 * The file is read in chunks of 1024 bytes.
 */
int main(int argc, char *argv[])
{
	int from_fd, to_fd, close_status;
	ssize_t num_read, num_written;
	char buffer[BUFFER_SIZE];

	if (argc =! 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	from_fd = open(argv[1], O_RDONLY);
	if (from_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	to_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (to_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(from_fd);
		exit(99);
	}
	while ((num_read = read(from_fd, buffer, BUFFER_SIZE)) > 0)
	{
		num_written = write(to_fd, buffer, num_read);
		if (num_written != num_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(from_fd);
			close(to_fd);
			exit(99);
		}
	}
	if (num_read < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close(from_fd);
		close(to_fd);
		exit(98);
	}
	close_status = close(from_fd);
	if (close_status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from_fd);
		exit(100);
	}
	close_status = close(to_fd);
	if (close_status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", to_fd);
		exit(100);
	}
	return (0);
}

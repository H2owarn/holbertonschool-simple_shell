#include <fcntl.h>
#include <unistd.h>
#include "main.h"
/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: The name of the file.
 * @text_content: A NULL terminated string to add at the end of the file.
 *
 * Return: 1 on success, or -1 on failure.
 *
 * Description:
 * - If filename is NULL, returns -1.
 * - If the file does not exist or if the program lacks the proper permissions,
 *   the function returns -1.
 * - If text_content is NULL,
 *   the file is left unchanged (but exists) and the function
 *   returns 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t bytes_written;
	size_t len = 0;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
	return (-1);
		if (text_content != NULL)
		{
			while (text_content[len])
				len++;
			if (len > 0)
			{
				bytes_written = write(fd, text_content, len);
				if (len > 0)
				{
					bytes_written = write(fd, text_content, len);
					if (bytes_written == -1 || (size_t)bytes_written != len)

					{
						close(fd);
						return (-1);
					}
				}
			}
		}
	close(fd);
	return (1);
}

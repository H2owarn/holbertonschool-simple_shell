#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>

#define BUFFER_SIZE 1024
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>

#define BUFFER_SIZE 1024
void print_error_and_exit(const char *message, int exit_code, const char *filename)
{
    dprintf(STDERR_FILENO, message, filename);
    exit(exit_code);
}

void close_file(int fd)
{
    if (close(fd) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
        exit(100);
    }
}

int main(int argc, char *argv[])
{
    int from_fd, to_fd;
    ssize_t num_read, num_written;
    char buffer[BUFFER_SIZE];

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }

    /* Open file_from */
    from_fd = open(argv[1], O_RDONLY);
    if (from_fd == -1)
        print_error_and_exit("Error: Can't read from file %s\n", 98, argv[1]);

    /* Open or create file_to */
    to_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    if (to_fd == -1)
    {
        close_file(from_fd);
        print_error_and_exit("Error: Can't write to %s\n", 99, argv[2]);
    }

    /* Copy data using buffer */
    while ((num_read = read(from_fd, buffer, BUFFER_SIZE)) > 0)
    {
        num_written = write(to_fd, buffer, num_read);
        if (num_written != num_read)
        {
            close_file(from_fd);
            close_file(to_fd);
            print_error_and_exit("Error: Can't write to %s\n", 99, argv[2]);
        }
    }

    if (num_read == -1)
    {
        close_file(from_fd);
        close_file(to_fd);
        print_error_and_exit("Error: Can't read from file %s\n", 98, argv[1]);
    }

    /* Close file descriptors */
    close_file(from_fd);
    close_file(to_fd);

    return 0;
}

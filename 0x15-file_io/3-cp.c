#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void exit_with_error(int code, const char *message)
{
    dprintf(STDERR_FILENO, "%s\n", message);
    exit(code);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
        exit_with_error(97, "Usage: cp file_from file_to");

    char *file_from = argv[1];
    char *file_to = argv[2];

    int from_fd = open(file_from, O_RDONLY);
    if (from_fd == -1)
        exit_with_error(98, "Error: Can't read from file %s");

    int to_fd = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
    if (to_fd == -1)
        exit_with_error(99, "Error: Can't write to file %s");

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    while ((bytes_read = read(from_fd, buffer, BUFFER_SIZE)) > 0)
    {
        bytes_written = write(to_fd, buffer, bytes_read);
        if (bytes_written == -1)
            exit_with_error(99, "Error: Can't write to file %s");
    }

    if (bytes_read == -1)
        exit_with_error(98, "Error: Can't read from file %s");

    if (close(from_fd) == -1)
        exit_with_error(100, "Error: Can't close fd %d");

    if (close(to_fd) == -1)
        exit_with_error(100, "Error: Can't close fd %d");

    return 0;
}


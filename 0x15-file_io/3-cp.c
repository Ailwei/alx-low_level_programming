#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024

/**
 * error_exit - Prints an error message and exits the program.
 * @message: The error message to print.
 * @exit_code: The exit code to use when terminating the program.
 */
void error_exit(const char *message, int exit_code)
{
    dprintf(STDERR_FILENO, "Error: %s\n", message);
    exit(exit_code);
}

/**
 * copy_file - Copies the content of one file to another file.
 * @file_from: The source file.
 * @file_to: The destination file.
 */
void copy_file(const char *file_from, const char *file_to)
{
    int fd_from, fd_to;
    ssize_t read_bytes, write_bytes;
    char buffer[BUF_SIZE];

    fd_from = open(file_from, O_RDONLY);
    if (fd_from == -1)
        error_exit("Can't read from file", 98);

    fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    if (fd_to == -1)
        error_exit("Can't write to file", 99);

    while ((read_bytes = read(fd_from, buffer, BUF_SIZE)) > 0)
    {
        write_bytes = write(fd_to, buffer, read_bytes);
        if (write_bytes != read_bytes)
            error_exit("Write error", 99);
    }

    if (read_bytes == -1)
        error_exit("Read error", 98);

    if (close(fd_from) == -1)
        error_exit("Can't close fd", 100);

    if (close(fd_to) == -1)
        error_exit("Can't close fd", 100);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success, non-zero on failure.
 */
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
        return (97);
    }

    const char *file_from = argv[1];
    const char *file_to = argv[2];

    copy_file(file_from, file_to);

    return 0;
}


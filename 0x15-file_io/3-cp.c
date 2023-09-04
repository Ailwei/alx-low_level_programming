#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(void);
void close_file(int fd);

/**
 * create_buffer - Allocates a 1024-byte buffer.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(void)
{
    char *buffer = malloc(1024);

    if (buffer == NULL)
    {
        dprintf(STDERR_FILENO, "Error: Can't allocate memory for buffer\n");
        exit(99);
    }

    return buffer;
}

/**
 * close_file - Closes a file descriptor.
 *
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
    if (close(fd) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close file descriptor %d\n", fd);
        exit(100);
    }
}

/**
 * main - Copies the contents of one file to another.
 *
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success, or appropriate exit codes on failure.
 */
int main(int argc, char *argv[])
{
    int from, to, r, w;
    char *buffer;

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }

    buffer = create_buffer();
    from = open(argv[1], O_RDONLY);
    to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

    if (from == -1 || to == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't open files for copying\n");
        free(buffer);
        exit(98);
    }

    do
    {
        r = read(from, buffer, 1024);

        if (r == -1)
        {
            dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
            free(buffer);
            exit(98);
        }

        w = write(to, buffer, r);

        if (w == -1)
        {
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
            free(buffer);
            exit(99);
        }

    } while (r > 0);

    free(buffer);
    close_file(from);
    close_file(to);

    return 0;
}


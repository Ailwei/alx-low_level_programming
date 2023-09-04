#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void print_error(const char *message) {
    dprintf(STDERR_FILENO, "%s\n", message);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_error("Usage: cp file_from file_to");
        return (97);
    }

    const char *file_from = argv[1];
    const char *file_to = argv[2];

    int fd_from = open(file_from, O_RDONLY);
    if (fd_from == -1) {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
        return (98);
    }

    int fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd_to == -1) {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
        return (99);
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0) {
        if (write(fd_to, buffer, bytes_read) != bytes_read) {
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
            close(fd_from);
            close(fd_to);
            return (99);
        }
    }

    if (bytes_read == -1) {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
        close(fd_from);
        close(fd_to);
        return (98);
    }

    if (close(fd_from) == -1) {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
        return (100);
    }

    if (close(fd_to) == -1) {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
        return (100);
    }

    return (0);
}



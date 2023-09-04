#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * error_exit - Print an error message and exit.
 * @code: The exit code.
 * @message: The error message.
 */
void error_exit(int code, const char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(code);
}

/**
 * read_textfile - Reads and prints a text file to the POSIX standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters it should read and print.
 *
 * Return: The actual number of letters it could read and print.
 *         0 on error or if the file can't be opened/read.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t n_read, n_written;
	char *buf;

	if (filename == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
	{
		close(fd);
		return (0);
	}
	n_read = read(fd, buf, letters);
	if (n_read == -1)
	{
		free(buf);
		close(fd);
		return (0);
	}
	n_written = write(STDOUT_FILENO, buf, n_read);
	free(buf);
	close(fd);

	if (n_written < n_read)
		return (0);
	return (n_written);
}

/**
 * create_file - Creates a file with specified text content.
 * @filename: The name of the file to create.
 * @text_content: The text content to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, len = 0, n_written;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);
	if (text_content != NULL)
	{
		while (text_content[len])
			len++;
		n_written = write(fd, text_content, len);
		if (n_written == -1)
		{
			close(fd);
			return (-1);
		}
	}
	close(fd);
	return (1);
}

/**
 * append_text_to_file - Appends text to the end of a file.
 * @filename: The name of the file.
 * @text_content: The text content to append.
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, len = 0, n_written;

	if (filename == NULL)
		return (-1);
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);
	if (text_content != NULL)
	{
		while (text_content[len])
			len++;
		n_written = write(fd, text_content, len);
		if (n_written == -1)
		{
			close(fd);
			return (-1);
		}
	}
	close(fd);
	return (1);
}

/**
 * main - Copies the content of one file to another.
 * @argc: The number of arguments.
 * @argv: The arguments.
 *
 * Return: 0 on success, otherwise an error code.
 */
int main(int argc, char **argv)
{
	int from_fd, to_fd;
	ssize_t n_read, n_written;
	char buffer[1024];

	if (argc != 3)
		error_exit(97, "Usage: cp file_from file_to");
	from_fd = open(argv[1], O_RDONLY);
	if (from_fd == -1)
		error_exit(98, "Error: Can't read from file NAME_OF_THE_FILE");
	to_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (to_fd == -1)
		error_exit(99, "Error: Can't write to NAME_OF_THE_FILE");
	while ((n_read = read(from_fd, buffer, sizeof(buffer))) > 0)
	{
		n_written = write(to_fd, buffer, n_read);
		if (n_written == -1)
			error_exit(99, "Error: Can't write to NAME_OF_THE_FILE");
	}
	if (n_read == -1)
		error_exit(98, "Error: Can't read from file NAME_OF_THE_FILE");
	if (close(from_fd) == -1)
		error_exit(100, "Error: Can't close fd FROM_FD_VALUE");
	if (close(to_fd) == -1)
		error_exit(100, "Error: Can't close fd TO_FD_VALUE");
	return (0);
}
}


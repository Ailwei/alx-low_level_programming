#include "main.h"
#include <stdlib.h>
/**
 * read_textfile - Read the specified number of letters
 * from a text file and print to STDOUT.
 * @filename: The name of the text file being read.
 * @letters: The number of letters to be read.
 *
 * Return: The actual number of bytes read and printed.
 * 0 when the function fails or the filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t file_descriptor, bytes_read, bytes_written;

	if (filename == NULL)
		return (0);
	/* Open the file in read-only mode */
	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (0);
	/* Allocate memory for the buffer to read the specified number of letters */
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(file_descriptor);
		return (0);
	}
	/* Read the specified number of letters from the file into the buffer */
	bytes_read = read(file_descriptor, buffer, letters);
	if (bytes_read == -1)
	{
		free(buffer);
		close(file_descriptor);
		return (0);
	}
	/* Write the content of the buffer to the standard output (STDOUT) */
	bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
	/* Free the allocated memory and close the file descriptor */
	free(buffer);
	close(file_descriptor);
	return (bytes_written);
}

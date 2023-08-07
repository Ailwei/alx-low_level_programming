#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>

/**
 * read_textfile - Reads and prints a text file to the POSIX standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed, 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	if (filename == NULL)
		return (0); /* Return 0 if filename is NULL */

	int fd = open(filename, O_RDONLY); /* Open the file in read-only mode */
	if (fd == -1)
		return (0); /* Return 0 if the file can't be opened */

	char buffer[1024]i#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>

/**
 * read_textfile - Reads and prints a text file to the POSIX standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed, 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	if (filename == NULL)
		return (0); /* Return 0 if filename is NULL */

	int fd = open(filename, O_RDONLY); /* Open the file in read-only mode */
	if (fd == -1)
		return (0); /* Return 0 if the file can't be opened */

	char buffer[1024]; /* Buffer to read data from the file */
	ssize_t total_read = 0; /* Total number of letters read */

	while (letters > 0)
	{
		ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
		if (bytes_read == -1)
		{
			close(fd);
			return (0); /* Return 0 if there's an error reading the file */
		}

		if (bytes_read == 0)
			break; /* Reached end of file */

		ssize_t bytes_to_print = (bytes_read < letters) ? bytes_read : letters;
		ssize_t bytes_written = write(STDOUT_FILENO, buffer, bytes_to_print);
		if (bytes_written == -1 || bytes_written != bytes_to_print)
		{
			close(fd);
			return (0); /* Return 0 if there's an error writing or not all bytes are written */
		}

		total_read += bytes_to_print;
		letters -= bytes_to_print;
	}

	close(fd);
	return (total_read);
}


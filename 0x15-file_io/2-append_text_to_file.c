#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: The name of the file.
 * @text_content: The NULL terminated string to add at the end of the file.
 *
 * Return: 1 on success, -1 on failure.
 * Do not create the file if it does not exist.
 * If filename is NULL, return -1.
 * If text_content is NULL, do not add anything to the file.
 * Return 1 if the file exists and -1 if the file does not exist
 * or if you do not have the required permissions to write the file.
 */
int append_text_to_file(const char *filename, char *text_content)

	FILE *file = fopen(filename, "a");
	int result = fputs(text_content, file);

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		return (1);
	if (file == NULL)
		return (0);

	fclose(file);

	return (result >= 0) ? 1 : -1;
}

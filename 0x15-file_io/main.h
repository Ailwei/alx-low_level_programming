#ifndef FILEIO_H
#define FILEIO_H


#include <sys/types.h>

#include <sys/stat.h>

#include <fcntl.h>

#include <unistd.h>

int create_file(const char *filename, char *text_content);
ssize_t read_textfile(const char *filename, size_t letters);
int _putchar(char c);
int append_text_to_file(const char *filename, char *text_content);
void printElfHeader(const ElfHeader *header);
#endif

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
/**
void exitWithError(const char *message);
void checkElfFile(const char *filename);
void printElfHeaderInfo(Elf64_Ehdr *header);
void printMagicNumbers(unsigned char *e_ident);
void printElfClass(unsigned char elf_class);
void printElfData(unsigned char elf_data);
void printElfVersion(unsigned char elf_version);
void printElfOSABI(unsigned char osabi);
void printElfABIVersion(unsigned char abi_version);
void printElfType(unsigned int elf_type);
void printElfEntryPoint(Elf64_Addr entry_point);
 */

#endif

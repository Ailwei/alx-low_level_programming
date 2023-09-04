#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>

/**
 * print_error - Prints error message to stderr and exits with status code 98.
 * @message: The error message to be displayed.
 */
void print_error(const char *message)
{
	fprintf(stderr, "Error: %s\n", message);
	exit(98);
}

/**
 * display_elf_header_info - Displays information contained in the ELF header.
 * @header: Pointer to the ELF header structure.
 */
void display_elf_header_info(const Elf64_Ehdr *header)
{
	printf("Magic: %02x %02x %02x %02x\n", header->e_ident[EI_MAG0],
	       header->e_ident[EI_MAG1], header->e_ident[EI_MAG2],
	       header->e_ident[EI_MAG3]);
	/* Display other fields of the ELF header as required */
	/* You can refer to 'struct elf' man page for the respective offsets & size */
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char *argv[])
{
	const char *filename;
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
		print_error("Usage: elf_header elf_filename");

	filename = argv[1];
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_error("Failed to open the file.");

	/* Read ELF header */
	if (read(fd, &header, sizeof(header)) != sizeof(header))
		print_error("Failed to read ELF header.");

	/* Check if it's a valid ELF file */
	if (memcmp(header.e_ident, ELFMAG, SELFMAG) != 0)
		print_error("Not an ELF file.");

	/* Display ELF header information */
	display_elf_header_info(&header);

	close(fd);
	return (0);
}


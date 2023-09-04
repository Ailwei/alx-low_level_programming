#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

/**
 * struct ElfHeader - ELF header structure
 * @e_ident: ELF identification bytes
 * @e_type: Object file type
 * @e_machine: Machine architecture
 * @e_version: ELF format version
 * @e_entry: Entry point virtual address
 * @e_phoff: Program header table file offset
 * @e_shoff: Section header table file offset
 * @e_flags: Processor-specific flags
 * @e_ehsize: ELF header size
 * @e_phentsize: Size of program header entry
 * @e_phnum: Number of program header entries
 * @e_shentsize: Size of section header entry
 * @e_shnum: Number of section header entries
 * @e_shstrndx: Section header table index of section name string table
 */
typedef struct ElfHeader
{
	char e_ident[16];
	uint16_t e_type;
	uint16_t e_machine;
	uint32_t e_version;
	uint64_t e_entry;
	uint64_t e_phoff;
	uint64_t e_shoff;
	uint32_t e_flags;
	uint16_t e_ehsize;
	uint16_t e_phentsize;
	uint16_t e_phnum;
	uint16_t e_shentsize;
	uint16_t e_shnum;
	uint16_t e_shstrndx;
} ElfHeader;

/**
 * printElfHeader - Print ELF header information
 * @header: Pointer to ELF header structure
 */
void printElfHeader(const ElfHeader *header)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < 16; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");
	printf("  Class:                             ");
	switch (header->e_ident[4])
	{
	case 1:
		printf("ELF32\n");
		break;
	case 2:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %02x>\n", header->e_ident[4]);
		break;
	}
	printf("  Data:                              %s\n", (header->e_ident[5] == 1) ? "2's complement, little endian" : "2's complement, big endian");
	printf("  Version:                           %u (current)\n", header->e_version);
	printf("  OS/ABI:                            %s\n", (header->e_ident[7] == 0) ? "UNIX - System V" : "<unknown>");
	printf("  ABI Version:                       %u\n", header->e_ident[8]);
	printf("  Type:                              ");
	switch (header->e_type)
	{
	case 1:
		printf("REL (Relocatable file)\n");
		break;
	case 2:
		printf("EXEC (Executable file)\n");
		break;
	case 3:
		printf("DYN (Shared object file)\n");
		break;
	default:
		printf("<unknown: %04x>\n", header->e_type);
		break;
	}
	printf("  Entry point address:               0x%lx\n", header->e_entry);
}
int main(int argc, char *argv[])
{
    const char *filename;
    int fd;
    ElfHeader header;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        return 98;
    }

    filename = argv[1];
    fd = open(filename, O_RDONLY);

    if (fd == -1)
    {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        return 98;
    }

    if (read(fd, &header, sizeof(header)) != sizeof(header))
    {
        fprintf(stderr, "Error reading ELF header: %s\n", strerror(errno));
        close(fd);
        return 98;
    }

    if (memcmp(header.e_ident, "\x7F""ELF", 4) != 0)
    {
        fprintf(stderr, "Error: Not an ELF file\n");
        close(fd);
        return 98;
    }

    printElfHeader(&header);

    close(fd);
    return 0;
}


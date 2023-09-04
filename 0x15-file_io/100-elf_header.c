#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include "main.h"

int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr header;
	const char *filename;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        return EXIT_FAILURE;
    }

    filename = argv[1];
    checkElfFile(filename);

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    
    if (read(fd, &header, sizeof(header)) != sizeof(header))
    {
        perror("Error reading ELF header");
        close(fd);
        return EXIT_FAILURE;
    }

    printElfHeaderInfo(&header);

    close(fd);
    return EXIT_SUCCESS;
}

void exitWithError(const char *message)
{
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}

void checkElfFile(const char *filename)
{
	unsigned char e_ident[EI_NIDENT];
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

   
    if (read(fd, e_ident, EI_NIDENT) != EI_NIDENT)
    {
        perror("Error reading ELF identification bytes");
        close(fd);
        exit(EXIT_FAILURE);
    }

    if (memcmp(e_ident, ELFMAG, SELFMAG) != 0)
    {
        exitWithError("Not an ELF file");
    }

    close(fd);
}

void printElfHeaderInfo(Elf64_Ehdr *header)
{
    printf("ELF Header:\n");
    printMagicNumbers(header->e_ident);
    printElfClass(header->e_ident[EI_CLASS]);
    printElfData(header->e_ident[EI_DATA]);
    printElfVersion(header->e_ident[EI_VERSION]);
    printElfOSABI(header->e_ident[EI_OSABI]);
    printElfABIVersion(header->e_ident[EI_ABIVERSION]);
    printElfType(header->e_type);
    printElfEntryPoint(header->e_entry);
}

void printMagicNumbers(unsigned char *e_ident)
{
	int i;
    printf(" Magic:");
    for (i = 0; i < EI_NIDENT; i++)
    {
        printf(" %02x", e_ident[i]);
    }
    printf("\n");
}

void printElfClass(unsigned char elf_class)
{
    printf(" Class: ");
    switch (elf_class)
    {
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("ELF64\n");
        break;
    default:
        printf("<unknown: %x>\n", elf_class);
        break;
    }
}

void printElfData(unsigned char elf_data)
{
    printf(" Data: ");
    switch (elf_data)
    {
    case ELFDATA2LSB:
        printf("2's complement, little endian\n");
        break;
    case ELFDATA2MSB:
        printf("2's complement, big endian\n");
        break;
    default:
        printf("<unknown: %x>\n", elf_data);
        break;
    }
}

void printElfVersion(unsigned char elf_version)
{
    printf(" Version: %d", elf_version);
    switch (elf_version)
    {
    case EV_CURRENT:
        printf(" (current)\n");
        break;
    default:
        printf("\n");
        break;
    }
}

void printElfOSABI(unsigned char osabi)
{
    printf(" OS/ABI: ");
    switch (osabi)
    {
    case ELFOSABI_NONE:
        printf("UNIX - System V\n");
        break;
    case ELFOSABI_HPUX:
        printf("UNIX - HP-UX\n");
        break;
    case ELFOSABI_NETBSD:
        printf("UNIX - NetBSD\n");
        break;
    case ELFOSABI_LINUX:
        printf("UNIX - Linux\n");
        break;
    case ELFOSABI_SOLARIS:
        printf("UNIX - Solaris\n");
        break;
    case ELFOSABI_IRIX:
        printf("UNIX - IRIX\n");
        break;
    case ELFOSABI_FREEBSD:
        printf("UNIX - FreeBSD\n");
        break;
    case ELFOSABI_TRU64:
        printf("UNIX - TRU64\n");
        break;
    case ELFOSABI_ARM:
        printf("ARM\n");
        break;
    case ELFOSABI_STANDALONE:
        printf("Standalone App\n");
        break;
    default:
        printf("<unknown: %x>\n", osabi);
        break;
    }
}

void printElfABIVersion(unsigned char abi_version)
{
    printf(" ABI Version: %d\n", abi_version);
}

void printElfType(unsigned int elf_type)
{
    printf(" Type: ");
    switch (elf_type)
    {
    case ET_NONE:
        printf("NONE (None)\n");
        break;
    case ET_REL:
        printf("REL (Relocatable file)\n");
        break;
    case ET_EXEC:
        printf("EXEC (Executable file)\n");
        break;
    case ET_DYN:
        printf("DYN (Shared object file)\n");
        break;
    case ET_CORE:
        printf("CORE (Core file)\n");
        break;
    default:
        printf("<unknown: %x>\n", elf_type);
        break;
    }
}

void printElfEntryPoint(Elf64_Addr entry_point)
{
    printf(" Entry point address: %#lx\n", entry_point);
}


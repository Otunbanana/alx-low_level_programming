#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stddef.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
* check_elf - Checks if a file is an ELF file.
* @e_ident: A pointer to an array containing the ELF magic numbers.
*
* Description: If the file is not an ELF file - exit with error code 98.
*/

/*Al Kimba, How far you? */
void check_elf(unsigned char *e_ident)
{
if (e_ident[EI_MAG0] != ELFMAG0 || e_ident[EI_MAG1] != ELFMAG1 ||
e_ident[EI_MAG2] != ELFMAG2 || e_ident[EI_MAG3] != ELFMAG3) {
fprintf(stderr, "Error: Not an ELF file\n");
exit(98);
}
}

/**
* print_magic - Prints the magic numbers of an ELF header.
* @e_ident: A pointer to an array containing the ELF magic numbers.
*
* Description: Magic numbers are separated by spaces.
*/
void print_magic(unsigned char *e_ident)
{
int i;
printf("  Magic:   ");
for (i = 0; i < EI_NIDENT; i++)
{
printf("%02x ", e_ident[i]);
}
printf("\n");
}

/**
* print_class - Prints the class of an ELF header.
* @e_ident: A pointer to an array containing the ELF class.
*/
void print_class(unsigned char *e_ident)
{
printf("  Class:                             ");
switch (e_ident[EI_CLASS])
{
case ELFCLASSNONE:
printf("none\n");
break;
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
break;
}
}

/**
* print_data - Prints the data of an ELF header.
* @e_ident: A pointer to an array containing the ELF class.
*/
void print_data(unsigned char *e_ident)
{
printf("  Data:                              ");
switch (e_ident[EI_DATA])
{
case ELFDATANONE:
printf("none\n");
break;
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
break;
}
}

/**
* print_version - Prints the version of an ELF header.
* @e_ident: A pointer to an array containing the ELF version.
*/
void print_version(unsigned char *e_ident)
{
printf("  Version:                           %d", e_ident[EI_VERSION]);
switch (e_ident[EI_VERSION])
{
case EV_CURRENT:
printf(" (current)\n");
break;
default:
printf("\n");
break;
}
}

/**
* print_osabi - Prints the OS/ABI of an ELF header.
* @e_ident: A pointer to an array containing the ELF version.
*/
void print_osabi(unsigned char *e_ident)
{
printf("  OS/ABI:                            ");
switch (e_ident[EI_OSABI])
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
printf("<unknown: %x>\n", e_ident[EI_OSABI]);
break;
}
}

/**
* print_type - Prints the type of an ELF header.
* @e_type: The ELF type.
* @e_ident: A pointer to an array containing the ELF class.
*/
void print_type(unsigned int e_type, unsigned char *e_ident)
{
if (e_ident[EI_DATA] == ELFDATA2MSB)
{
e_type >>= 8;
}

printf("  Type:                              ");
switch (e_type)
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
printf("<unknown: %x>\n", e_type);
break;
}
}

/**
* print_entry - Prints the entry point of an ELF header.
* @e_entry: The entry point.
* @e_ident: A pointer to an array containing the ELF class.
*/
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
printf("  Entry point address:               ");
if (e_ident[EI_CLASS] == ELFCLASS32)
{
printf("%#x\n", (unsigned int) e_entry);
}
else
{
printf("%#lx\n", e_entry);
}
}

/**
* close_elf - Closes an ELF file.
* @elf: The file descriptor of the ELF file.
*/
void close_elf(int elf)
{
if (close(elf) == -1)
{
perror("close");
exit(98);
}
}

/**
* main - Entry point.
* @argc: The number of arguments.
* @argv: The arguments vector.
*
* Return: 0 on success, 98 on failure.
*/
int main(int argc, char *argv[])
{
int elf;
struct stat st;
unsigned char e_ident[EI_NIDENT];
unsigned int e_type;
unsigned long int e_entry;

if (argc != 2)
{
fprintf(stderr, "Usage: %s <ELF file>\n", argv[0]);
return (98);
}

elf = open(argv[1], O_RDONLY);
if (elf == -1)
{
perror("open");
return (98);
}

if (fstat(elf, &st) == -1)
{
perror("fstat");
close_elf(elf);
return (98);
}

if (read(elf, e_ident, EI_NIDENT) == -1)
{
perror("read");
close_elf(elf);
return (98);
}

check_elf(e_ident);

printf("ELF Header:\n");
print_magic(e_ident);
print_class(e_ident);
print_data(e_ident);
print_version(e_ident);
print_osabi(e_ident);


/* Read the type and entry point from the ELF header */
if (lseek(elf, offsetof(Elf64_Ehdr, e_type), SEEK_SET) == -1)
{
perror("lseek");
close_elf(elf);
return (98);
}
if (read(elf, &e_type, sizeof(e_type)) == -1)
{
perror("read");
close_elf(elf);
return (98);
}
if (lseek(elf, offsetof(Elf64_Ehdr, e_entry), SEEK_SET) == -1)
{
perror("lseek");
close_elf(elf);
return (98);
}
if (read(elf, &e_entry, sizeof(e_entry)) == -1)
{
perror("read");
close_elf(elf);
return (98);
}

print_type(e_type, e_ident);
print_entry(e_entry, e_ident);

close_elf(elf);
return (0);
}

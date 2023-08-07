#include <elf.h>
#include "main.h"

#define REV(n) (((n) << 24) | (((n) >> 16) << 24) >> 16 | \
(((n) << 16) >> 24) << 16 | ((n) >> 24))
/**
* verify- verify the file if is an ELF
* @e_ident: ELF struct
* return: 0.
*/

void verify(unsigned char *e_ident)
{
if (e_ident[0] == 0x7f && e_ident[1] == 'E' && e_ident[2] == 'L' && e_ident[3] == 'F')
{
printf("ELF Header:\n");
}
else
{
dprintf(STDERR_FILENO, "Error: This file is not a valid ELF\n");
exit(98);
}
}
/**
* magic - prints magic number
* @e_ident: ELF struct
* return: 0.
*/
void magic(unsigned char *e_ident)
{
int i;
int limit = EI_NIDENT - 1;

printf("  Magic:   ");
for (i = 0; i < limit; i++)
{
printf("%02x ", e_ident[i]);
}
printf("%02x\n", e_ident[i]);
}
/**
* class - print ELF class
* @e_ident: ELF struct
* return: 0.
*/
void class(unsigned char *e_ident)
{
printf("  Class:                             ");
switch (e_ident[EI_CLASS])
{
case ELFCLASSNONE:
printf("This class is invalid\n");
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
* data - print data type
* @e_ident: ELF struct
* return: 0
*/
void data(unsigned char *e_ident)
{
printf("  Data:                              ");
switch (e_ident[EI_DATA])
{
case ELFDATANONE:
printf("Unknown data format\n");
break;
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_DATA]);
break;
}
}
/**
* version - print the file version
* @e_ident: ELF struct
* return: 0.
*/

void version(unsigned char *e_ident)
{
printf("  Version:                           ");
if (e_ident[EI_VERSION] == EV_CURRENT)
{
printf("%i (current)\n", EV_CURRENT);
}
else
{
printf("%i\n", e_ident[EI_VERSION]);
}
}
/**
* main - read ELF file.
* @argc: the number of args
* @argv: the Args variable
* Return: 0 in success
*/
int main(int argc, char *argv[])
{
int fd, _read, _close;
Elf64_Ehdr *file;

if (argc != 2)
{
dprintf(STDERR_FILENO, "Usage: %s <elf_file>\n", argv[0]);
exit(98);
}

file = malloc(sizeof(Elf64_Ehdr));
if (file == NULL)
{
dprintf(STDERR_FILENO, "Error: Memory allocation failed\n");
exit(98);
}

fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}

_read = read(fd, file, sizeof(Elf64_Ehdr));
if (_read == -1)
{
free(file);
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}

verify(file->e_ident);
magic(file->e_ident);
class(file->e_ident);
data(file->e_ident);
version(file->e_ident);

return (0);
}

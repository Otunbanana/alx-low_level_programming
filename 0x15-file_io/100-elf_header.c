#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

int main(int argc, char *argv[])
{
int fd;
Elf64_Ehdr elf_header;
ssize_t n;

if (argc != 2)
{
fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
exit(98);
}

fd = open(argv[1], O_RDONLY);
if (fd < 0)
{
fprintf(stderr, "Error: cannot open file '%s'\n", argv[1]);
exit(98);
}

n = read(fd, &elf_header, sizeof(Elf64_Ehdr));
if (n != sizeof(Elf64_Ehdr) || memcmp(elf_header.e_ident, ELFMAG, SELFMAG) != 0)
{
fprintf(stderr, "Error: '%s' is not an ELF file\n", argv[1]);
exit(98);
}

printf("Magic:   ");
for (int i = 0; i < EI_NIDENT; i++)
{
printf("%02x ", elf_header.e_ident[i]);
}
printf("\n");

printf("Class: %s\n", elf_header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
printf("Data: %s\n", elf_header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's 
complement, little endian" : "2's complement, big endian");
printf("Version: %d (current)\n", elf_header.e_ident[EI_VERSION]);
printf("OS/ABI:                            ");
switch (elf_header.e_ident[EI_OSABI])
{
case ELFOSABI_SYSV: printf("UNIX System V ABI\n"); break;
case ELFOSABI_HPUX: printf("HP-UX ABI\n"); break;
case ELFOSABI_NETBSD: printf("NetBSD ABI\n"); break;
case ELFOSABI_LINUX: printf("Linux ABI\n"); break;
case ELFOSABI_SOLARIS: printf("Solaris ABI\n"); break;
case ELFOSABI_AIX: printf("AIX ABI\n"); break;
case ELFOSABI_IRIX: printf("IRIX ABI\n"); break;
case ELFOSABI_FREEBSD: printf("FreeBSD ABI\n"); break;
case ELFOSABI_OPENBSD: printf("OpenBSD ABI\n"); break;
case ELFOSABI_ARM: printf("ARM architecture ABI\n"); break;
case ELFOSABI_STANDALONE: printf("Standalone (embedded) ABI\n"); break;
default: printf("<unknown>\n"); break;
}
printf("ABI Version: %d\n", elf_header.e_ident[EI_ABIVERSION]);

printf("Type:                              ");
switch (elf_header.e_type)
{
case ET_NONE: printf("No file type\n"); break;
case ET_REL: printf("Relocatable file\n"); break;
case ET_EXEC: printf("Executable file\n"); break;
case ET_DYN: printf("Shared object file\n"); break;
case ET_CORE: printf("Core file\n"); break;
default: printf("<unknown>\n"); break;
}

printf("Entry point address: 0x%lx\n", (unsigned long)elf_header.e_entry);

close(fd);
return (0);
}

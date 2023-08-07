#include <stdio.h>
#include <stdlib.h>
#include <elf.h>

/**
* main - displays the information contained in the ELF header at the start
* of an ELF file.
*
* @param argc: The number of arguments passed on the command line.
* @param argv: The arguments passed on the command line.
* @return 0 on success, 1 on error.
*/

int main(int argc, char *argv[]) {
/* Check the number of arguments. */
FILE *fp;
Elf32_Ehdr ehdr;
size_t nread;
if (argc != 2)
{
fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
return (1);
}

/* Open the file. */
fp = fopen(argv[1], "r");
if (fp == NULL)
{
perror("fopen");
return (1);
}

/* Read the ELF header. */
nread = fread(&ehdr, sizeof(ehdr), 1, fp);
if (nread != 1)
{
perror("fread");
return (1);
}

/* Print the ELF header information. */
printf("ELF Header:\n");
printf("  Magic:   %#x\n", ehdr.e_ident[EI_MAG0]);
printf("  Class:                             %d\n", ehdr.e_class);
printf("  Data:                              %d\n", ehdr.e_data);
printf("  Version:                           %d (current)\n", ehdr.e_version);
printf("  OS/ABI:                            %s\n", elf_get_osabi(ehdr.e_ident[EI_OSABI]));
printf("  ABI Version:                       %d\n", ehdr.e_abiversion);
printf("  Type:                              %d (%s)\n", ehdr.e_type,
ehdr.e_type == ET_EXEC ? "Executable file" :
ehdr.e_type == ET_DYN ? "Shared object file" :
ehdr.e_type == ET_REL ? "Relocatable file" :
ehdr.e_type == ET_CORE ? "Core file" : "Unknown");
printf("  Entry point address:               0x%x\n", ehdr.e_entry);

/* Close the file. */
fclose(fp);

return (0);
}

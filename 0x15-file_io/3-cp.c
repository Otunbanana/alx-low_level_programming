#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
* __exit - prints error messages and exits with exit value
* @error: num is either exit value or file descriptor
* @s: str is a name, either of the two filenames
* @fd: file descriptor
* Return: 0 on success
**/
/* oga kimba! how far? */
int __exit(int error, char *s, int fd)
{
switch (error)
{
case 97:
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(error);
case 98:
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", s);
exit(error);
case 99:
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", s);
exit(error);
case 100:
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(error);
default:
return (0);
}
}

/**
* main - copies one file to another
* @argc: should be 3 (./a.out copyfromfile copytofile)
* @argv: is file to copy
* Return: 0 (success), 97-100 (exit value errors)
*/
int main(int argc, char *argv[])
{
int fd_from, fd_to, n_read, n_written;
char buffer[1024];

if (argc != 3)
__exit(97, NULL, 0);

fd_from = open(argv[1], O_RDONLY);
if (fd_from == -1)
__exit(98, argv[1], 0);

fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (fd_to == -1)
__exit(99, argv[2], 0);

while ((n_read = read(fd_from, buffer, 1024)) > 0)
{
n_written = write(fd_to, buffer, n_read);
if (n_written == -1 || n_written != n_read)
__exit(99, argv[2], 0);
}

if (n_read == -1)
__exit(98, argv[1], 0);

if (close(fd_from) == -1)
__exit(100, NULL, fd_from);

if (close(fd_to) == -1)
__exit(100, NULL, fd_to);

return (0);
}


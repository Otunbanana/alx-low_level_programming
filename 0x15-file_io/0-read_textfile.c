#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

/**
* read_textfile - reads a text file and prints it to the POSIX standard output
*
* @filename: name of the file to read
* @letters: number of letters to read and print
*
* Return: the actual number of letters it could read and print, or 0 on failure
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
int fd;
ssize_t nread, nwritten;
char *buf;

if (filename == NULL)
return (0);

buf = malloc(sizeof(char) * (letters + 1));
if (buf == NULL)
return (0);

fd = open(filename, O_RDONLY);
if (fd == -1)
{
free(buf);
return (0);
}

nread = read(fd, buf, letters);
if (nread == -1)
{
free(buf);
close(fd);
return (0);
}

buf[nread] = '\0';
nwritten = write(STDOUT_FILENO, buf, nread);
if (nwritten == -1 || nwritten != nread)
{
free(buf);
close(fd);
return (0);
}

free(buf);
close(fd);
return (nwritten);
}


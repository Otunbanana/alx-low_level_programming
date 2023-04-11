#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
int fd_from, fd_to;
ssize_t nread;
char buffer[BUFFER_SIZE];
struct stat st;

/* Check the number of arguments*/
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
exit(97);
}

/* Open the file_from for reading*/
fd_from = open(argv[1], O_RDONLY);
if (fd_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}

/* Truncate the file_to if it exists*/
fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
if (fd_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
exit(99);
}

/* Copy the content of the file_from to the file_to*/
while ((nread = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
if (write(fd_to, buffer, nread) != nread)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
exit(99);
}
}
if (nread == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}

/* Check the file size of the file_from and set the permissions of the file_to*/
if (fstat(fd_from, &st) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't get file size of %s\n", argv[1]);
exit(100);
}
if (fchmod(fd_to, st.st_mode) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't set file permissions of %s\n", argv[2]);
exit(100);
}

/* Close the file descriptors*/
if (close(fd_from) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
exit(100);
}
if (close(fd_to) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
exit(100);
}

return (0);
}

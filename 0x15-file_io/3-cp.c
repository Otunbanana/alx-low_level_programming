#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "main.h"
#define BUFFER_SIZE 1024

int open_file_for_reading(const char *file_name);
int open_file_for_writing(const char *file_name);
void copy_file_content(int fd_from, int fd_to);
void set_file_permissions(const char *file_name, int fd_from);
void close_file(int fd, const char *file_name);

/**
* main - Entry point for the cp program.
* @argc: The number of command-line arguments.
* @argv: An array of strings containing the command-line arguments.
* Return: On success, returns 0. On failure, returns a non-zero value.
*/

int main(int argc, char *argv[])
{
int fd_from, fd_to;

/* Check the number of arguments */
if (argc != 3)
{
fprintf(stderr, "Usage: %s file_from file_to\n", argv[0]);
exit(97);
}

/* Open the file_from for reading */
fd_from = open_file_for_reading(argv[1]);

/*
 * Open the file_to for writing
 * (and creating if it does not exist)
*/
fd_to = open_file_for_writing(argv[2]);

/* Copy the content of the file_from to the file_to*/
copy_file_content(fd_from, fd_to);

/* Set the file permissions of the file_to*/
set_file_permissions(argv[2], fd_from);

/* Close the file descriptors*/
close_file(fd_from, argv[1]);
close_file(fd_to, argv[2]);

return (0);
}

/**
* open_file_for_reading - Opens a file for reading.
* @file_name: The name of the file to be opened.
* Return: On success, returns a file descriptor for the opened file.
*/

int open_file_for_reading(const char *file_name)
{
int fd = open(file_name, O_RDONLY);
if (fd == -1)
{
fprintf(stderr, "Error: Can't read from file %s\n", file_name);
exit(98);
}
return (fd);
}

/**
* open_file_for_writing - Opens a file for writing.
* @file_name: The name of the file to be opened.
* Return: On success, returns a file descriptor for the opened file.
*/

int open_file_for_writing(const char *file_name)
{
int fd;
fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
if (fd == -1)
{
fprintf(stderr, "Error: Can't write to %s\n", file_name);
exit(99);
}
return (fd);
}

/**
* copy_file_content - Copies the contents of one file to another.
* @fd_from: The name of the source file.
* @fd_to: The name of the destination file.
* Return: On success, returns 1. On failure, prints an error
* message to the standard error stream and exits with a non-zero value.
*/

void copy_file_content(int fd_from, int fd_to)
{
ssize_t nread;
char buffer[BUFFER_SIZE];
while ((nread = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
if (write(fd_to, buffer, nread) != nread)
{
fprintf(stderr, "Error: Can't write to file %d\n", fd_to);
exit(99);
}
}
if (nread == -1)
{
fprintf(stderr, "Error: Can't read from file descriptor %d\n", fd_from);
exit(98);
}
}

/**
* set_file_permissions - Sets the permissions of a file.
* @file_name: The name of the file.
* @fd_from: The name of the source file.
* Return: On success, returns 0. On failure, prints an error
* message to the standard error stream and exits with code 100.
*/

void set_file_permissions(const char *file_name, int fd_from)
{
struct stat st;
if (fstat(fd_from, &st) == -1)
{
fprintf(stderr, "Error: Can't get file size of %s\n", file_name);
exit(100);
}
if (fchmod(fd_from, st.st_mode) == -1)
{
fprintf(stderr, "Error: Can't set file permissions of %s\n", file_name);
exit(100);
}
}

/**
* close_file - Closes a file descriptor.
* @fd: The file descriptor to be closed.
* @file_name: The name of the file.
* Return: On success, returns 0. On failure, prints an error
* message to the standard error stream and exits with code 100.
*/

void close_file(int fd, const char *file_name)
{
if (close(fd) == -1)
{
fprintf(stderr, "Error: Can't close file %d of file %s", fd, file_name);
exit(101);
}
}

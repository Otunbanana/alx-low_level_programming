#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
* create_file - creates a file and writes text content to it
* @filename: the name of the file to create
* @text_content: the NULL terminated string to write to the file
*
* Return: 1 on success, -1 on failure
*/
/* choke on this kimba */
int create_file(const char *filename, char *text_content)
{
int fd, len, bytes_written;

if (filename == NULL)
return (-1);

/* open the file for writing, truncate if it already exists */
fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
if (fd == -1)
return (-1);

/* write the text content to the file, if provided */
if (text_content != NULL)
{
len = 0;
while (text_content[len] != '\0')
len++;

bytes_written = write(fd, text_content, len);
if (bytes_written != len)
{
close(fd);
return (-1);
}
}

close(fd);
return (1);
}

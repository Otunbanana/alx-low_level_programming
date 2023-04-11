#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
* append_text_to_file - Appends text to the end of a file.
*
* @filename: The name of the file.
* @text_content: The text to be appended to the file.
*
* Return: On success, returns 1. On failure, returns -1.
*/
int append_text_to_file(const char *filename, char *text_content)
{
int fd, len, wrote;

if (!filename)
return (-1);

/* Open file if it exists */
fd = open(filename, O_WRONLY | O_APPEND);
if (fd == -1)
return (-1);

/* If nothing to write, still successful */
if (!text_content)
{
close(fd);
return (1);
}

/* Write text_content to file */
len = 0;
while (text_content[len] != '\0')
len++;

wrote = write(fd, text_content, len);
if (wrote == -1 || wrote != len)
{
close(fd);
return (-1);
}

/* Close file */
close(fd);

return (1);
}

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
FILE *file;
if (filename == NULL)
return (-1);

file = fopen(filename, "a");
if (file == NULL)
return (-1);

if (text_content != NULL)
fprintf(file, "%s", text_content);

fclose(file);
return (1);
}


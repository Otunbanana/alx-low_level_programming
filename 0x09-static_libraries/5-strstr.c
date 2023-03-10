#include "main.h"
#include <string.h>
/**
* _strstr - locates a substring
* @haystack: input array
* @needle: bytes to accept
* Return: char pointer
*/

char *_strstr(char *haystack, char *needle)
{
size_t needle_len = strlen(needle);
if (needle_len == 0)
{
return (haystack);
}
while (*haystack)
{
if (strncmp(haystack, needle, needle_len) == 0)
{
return (haystack);
}
haystack++;
}
return (0);
}

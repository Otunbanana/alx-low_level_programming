#include "main.h"
/**
* _strpbrk - gets the length of a prefix substring.
* @s: input array
* @accept: bytes to accept
* Return: pointer
*/

char *_strpbrk(char *s, char *accept)
{
char *p;
while (*s != '\0')
{
for (p = accept; *p != '\0'; p++)
{
if (*s == *p)
{
return (s);
}
}
s++;
}
return (0);
}

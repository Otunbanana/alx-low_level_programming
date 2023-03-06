#include "main.h"
/**
* _strspn - gets the length of a prefix substring.
* @s: input array
* @accept: bytes to accept
* Return: # of bytes the initial segment of s
*/

unsigned int _strspn(char *s, char *accept)
{
unsigned int count = 0;
int found = 1;
while (*s != '\0' && found)
{
found = 0;
for (char *p = accept; *p != '\0'; p++)
{
if (*s == *p)
{
found = 1;
count++;
break;
}
}
s++;
}
return (count);
}

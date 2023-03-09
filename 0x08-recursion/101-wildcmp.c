#include "main.h"
#include <stdio.h>
#include <string.h>
/**
* wildcmp - 1 if the strings can be considered identical
* @s1: char 1
* @s2: char 2
* Return: Boolean
*/

int wildcmp(char *s1, char *s2)
{
if (*s1 == '\0' && *s2 == '\0')
{
return (1);
}
if (*s2 == '*')
{
if (*(s1 + 1) != '\0' && *(s2 + 1) != '\0')
{
if (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1))
{
return (1);
}
}
else if (*(s1 + 1) != '\0' && *(s2 + 1) == '\0')
{
return (1);
}
else if (*(s1 + 1) == '\0' && *(s2 + 1) == '\0')
{
return (1);
}
}
else if (*s1 == *s2)
{
return (wildcmp(s1 + 1, s2 + 1));
}
return (0);
}

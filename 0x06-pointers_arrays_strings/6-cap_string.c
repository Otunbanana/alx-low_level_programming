#include "main.h"
#include <stdio.h>

/**
* cap_string - ...
* @s: ...
*
* Return: char value
*/

char *cap_string(char *s)
{
int i = 0;

if (s[i] >= 'a' && s[i] <= 'z')
{
s[i] -= 32;
}

while (s[i] != '\0')
{

if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' ||
s[i] == ',' || s[i] == ';' || s[i] == '.' ||
s[i] == '!' || s[i] == '?' || s[i] == '"' ||
s[i] == '(' || s[i] == ')' || s[i] == '{' || s[i] == '}')
{

if (s[i + 1] >= 'a' && s[i + 1] <= 'z')
{
s[i + 1] -= 32;
}
}

i++;
}

return (s);
}

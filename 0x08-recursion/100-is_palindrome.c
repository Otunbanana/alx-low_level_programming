#include "main.h"
#include <string.h>
/**
* _strlen_recursion - length
* @s: char
* Return: length
**/

int is_palindrome(char *s) {
int len = strlen(s);
int i;
for (i = 0; i < len / 2; i++)
{
if (s[i] != s[len-1-i])
{
return (0);
}
}
return (1);
}


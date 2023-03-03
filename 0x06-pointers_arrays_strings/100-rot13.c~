#include "main.h"
/**
* rot13 - encodes a string into rot13
* @n: string
* Return: string encoded
**/

char *rot13(char *n)
{
int i;

for (i = 0; n[i] != '\0'; i++)
{
if (n[i] >= 'a' && n[i] <= 'z')
{
n[i] = ((n[i] - 'a') + 13) % 26 + 'a';
}
else if (n[i] >= 'A' && n[i] <= 'Z')
{
n[i] = ((n[i] - 'A') + 13) % 26 + 'A';
}
}

return (n);
}

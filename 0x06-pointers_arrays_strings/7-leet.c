#include "main.h"
/**
* leet - Encodes a string into 1337
* @s: The string to encode
*
* Return: The encoded string
*/

char *leet(char *s)
{
int i, j;
char letter[] = {'A', 'E', 'O', 'T', 'L'};
char digit[] = {'4', '3', '0', '7', '1'};

for (i = 0; s[i] != '\0'; i++)
{
for (j = 0; j < 5; j++)
{
if (s[i] == letter[j] || s[i] == letter[j] + 32)
{
s[i] = digit[j];
break;
}
}
}

return (s);
}

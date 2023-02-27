#include "main.h"
#include <string.h>
/**
* print_rev - prints string in reverse
* @s: String to print
*
* Return: void
*/
void print_rev(char *s)
{
int i;
int leng;
leng = strlen(s);

for (i = leng - 1; i >= 0; i--)
{
_putchar(s[i]);
}
_putchar('\n');
}

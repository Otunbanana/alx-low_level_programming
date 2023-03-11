#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "main.h"
#include <string.h>
/**
* main - adds positive numbers
* @argc: argument count
* @argv: argument vector
*
* Return: Always zero
*/

int main(int argc, char *argv[])
{
int sum = 0;
int i;
int j;
int len;
for (i = 1; i < argc; i++)
{
len = strlen(argv[i]);
for (j = 0; j < len; j++)
{
if (!isdigit(argv[i][j]))
{
printf("Error\n");
return (1);
}
}
sum += atoi(argv[i]);
}
printf("%d\n", sum);
return (0);
}

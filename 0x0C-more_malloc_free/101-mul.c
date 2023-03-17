#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"

#define MAX_DIGITS 1000

/**
* reverse - reverse numbers
* @str: input string
*
* Return: Always 0.
*/

void reverse(char *str)
{
int i;
int j;
i = 0,
j = strlen(str) - 1;
while (i < j)
{
char temp = str[i];
str[i] = str[j];
str[j] = temp;
i++;
j--;
}
}

/**
* *validate_input - multiplies two positive numbers
* @input: user input
*
* Return: Always 0.
*/

int validate_input(char *input)
{
int i;
i = 0;
while (input[i] != '\0')
{
if (!isdigit(input[i]))
{
return (0);
}
i++;
}
return (1);
}

/**
* *multiply - multiplies two positive numbers
* @num1: user input 1
* @num2: user input 2
* @result: result
*
* Return: Always 0.
*/

void multiply(char *num1, char *num2, char *result)
{
int len1, len2, *res, i, j, digit2, product, carry, digit1;
len1 = strlen(num1);
len2 = strlen(num2);
res = new int[len1 + len2]();

for (i = 0; i < len1; i++)
{
carry = 0;
digit1 = num1[len1 - i - 1] - '0';

for (j = 0; j < len2; j++)
{
digit2 = num2[len2 - j - 1] - '0';
product = digit1 *digit2 + carry + res[i + j];
res[i + j] = product % 10;
carry = product / 10;
}
if (carry > 0)
res[i + len2] += carry;
}
i = len1 + len2 - 1;
while (i >= 0 && res[i] == 0)
i--;
if (i == -1)
strcpy(result, "0");
else
{
j = 0;
while (i >= 0)
result[j] = res[i--] + '0', j++;
result[j] = '\0';
}
delete[] res;
reverse(result);
}


/**
* main - run program
* @argc: first
* @argv: second
*
* Return: zero.
*/

int main(int argc, char **argv)
{
if (argc != 3)
{
printf("Error\n");
return (98);
}
if (!validate_input(argv[1]) || !validate_input(argv[2]))
{
printf("Error\n");
return (98);
}

char num1[MAX_DIGITS];
char num2[MAX_DIGITS];
char result[MAX_DIGITS * 2];

strcpy(num1, argv[1]);
strcpy(num2, argv[2]);

multiply(num1, num2, result);
printf("%s\n", result);

return (0);
}

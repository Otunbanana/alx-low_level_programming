#include "main.h"
/**
  * _strlen - Returns the length of a string
  *
  * @s: String to count
  * 
  * Return: String len
  */
int _strlen(char *s)
{
int c;

for (; *s !='\0'; s++)
{
c++;
}
return (c);
}

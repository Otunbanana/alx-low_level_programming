#include "main.h"
#include <string.h>

/**
* check_palindrome - recursive helper function for is_palindrome
* @s: string to check
* @left: index of leftmost character to compare
* @right: index of rightmost character to compare
* Return: 1 if palindrome, 0 otherwise
**/
int check_palindrome(char *s, int left, int right)
{
if (left >= right)
{
return (1);
}
if (s[left] != s[right])
{
return (0);
}
return (check_palindrome(s, left + 1, right - 1));
}

/**
* is_palindrome - check if string is a palindrome
* @s: string to check
* Return: 1 if palindrome, 0 otherwise
**/
int is_palindrome(char *s)
{
int len = strlen(s);
return (check_palindrome(s, 0, len - 1));
}

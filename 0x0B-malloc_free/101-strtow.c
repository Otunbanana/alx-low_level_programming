#include <stdlib.h>
#include <string.h>

/**
* **strtow - splits a string into words
* @str: string
*
* Return: Always zero
*/

char **strtow(char *str)
{
char **words;
int i, j, k, len, wordcount;

if (str == NULL || *str == '\0')
return (NULL);

len = strlen(str);
wordcount = 0;

for (i = 0; i < len; i++)
{
if (!isspace(str[i]) && (i == 0 || isspace(str[i - 1])))
wordcount++;
}

words = (char **) malloc((wordcount + 1) * sizeof(char *));
if (words == NULL)
return (NULL);

i = 0;
j = 0;
while (i < len && j < wordcount)
{
while (isspace(str[i]))
i++;
k = i;
while (k < len && !isspace(str[k]))
k++;
words[j] = (char *) malloc((k - i + 1) * sizeof(char));
if (words[j] == NULL)
return (NULL);
strncpy(words[j], str + i, k - i);
words[j][k - i] = '\0';
j++;
i = k;
}

words[j] = NULL;

return (words);
}

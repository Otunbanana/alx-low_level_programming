#include <stdlib.h>
#include "lists.h"

/**
* free_listint2 - frees a listint_t list
* @head: pointer to the head of the list
*
* Description: This function frees a listint_t list and sets the head to NULL.
*/
void free_listint2(listint_t **head)
{
listint_t *current, *temp;

if (head == NULL)
return;

current = *head;

while (current != NULL)
{
temp = current;
current = current->next;
free(temp);
}

*head = NULL;
}


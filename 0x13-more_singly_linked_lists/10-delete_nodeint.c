#include "lists.h"
#include <stdlib.h>

/**
* delete_nodeint_at_index - deletes the node at index of listint_t linked list
* @head: pointer to the head of the list
* @index: index of the node that should be deleted
*
* Return: 1 if successful, -1 if failed
*/
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
listint_t *current, *prev;
unsigned int i;

if (*head == NULL)
return (-1);

if (index == 0)
{
*head = (*head)->next;
return (1);
}

prev = NULL;
current = *head;
for (i = 0; i < index; i++)
{
if (current == NULL)
return (-1);
prev = current;
current = current->next;
}

prev->next = current->next;
free(current);

return (1);
}

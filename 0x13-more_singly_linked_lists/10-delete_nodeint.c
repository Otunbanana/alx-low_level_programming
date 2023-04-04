#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
* delete_nodeint_at_index - deletes the node at index of
* a listint_t linked list
* @head: pointer to a pointer to the head of the list
* @index: index of the node to delete
*
* Return: 1 if it succeeded, -1 if it failed
*/
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
listint_t *current = *head, *prev = NULL;
unsigned int i;

if (*head == NULL)
return (-1);

if (index == 0)
{
*head = (*head)->next;
free(current);
return (1);
}

for (i = 0; current != NULL && i < index; i++)
{
prev = current;
current = current->next;
}

if (current == NULL)
return (-1);

prev->next = current->next;
free(current);
return (1);
}


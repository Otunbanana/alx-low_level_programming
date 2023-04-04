#include <stdlib.h>
#include "lists.h"

/**
* pop_listint - deletes the head node of a linked list and returns its data
* @head: pointer to the head node of the linked list
*
* Return: the data of the deleted head node, or 0 if the linked list is empty
*/
int pop_listint(listint_t **head)
{
int n;
listint_t *temp;

if (*head == NULL)
return (0);

temp = *head;
*head = (*head)->next;
n = temp->n;
free(temp);

return (n);
}


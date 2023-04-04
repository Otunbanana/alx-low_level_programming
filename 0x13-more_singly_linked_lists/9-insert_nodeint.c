#include "lists.h"
#include <stdlib.h>

/**
* insert_nodeint_at_index - inserts a new node at a given position.
* @head: pointer to a pointer to the first element of the list.
* @idx: index of the list where the new node should be added.
* @n: integer to be included in the new node.
*
* Return: the address of the new node, or NULL if it failed.
*/
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
unsigned int i = 0;
listint_t *new_node, *current;

if (head == NULL)
return (NULL);

new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
return (NULL);

new_node->n = n;
current = *head;

if (idx == 0)
{
new_node->next = current;
*head = new_node;
return (new_node);
}

while (i < idx - 1)
{
if (current == NULL)
{
free(new_node);
return (NULL);
}
current = current->next;
i++;
}

new_node->next = current->next;
current->next = new_node;

return (new_node);
}


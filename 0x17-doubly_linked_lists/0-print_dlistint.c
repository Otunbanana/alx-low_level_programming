#include "lists.h"

/**
* print_dlistint - Prints all elements of a dlistint_t list
* @h: Pointer to the head of the list
*
* Description: This function traverses a doubly linked list of type dlistint_t,
*              printing the value of each node. It starts from the given head
*              pointer and continues until the end of the list, counting and
*              printing each element.
*
* Return: The number of nodes in the list
*/
size_t print_dlistint(const dlistint_t *h)
{
size_t count = 0;

while (h != NULL)
{
printf("%d\n", h->n);
h = h->next;
count++;
}
return (count);
}

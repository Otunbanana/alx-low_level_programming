#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
* print_listint_safe - Prints a listint_t linked list.
* @head: A pointer to the head of the list.
*
* Return: The number of nodes in the list.
*/
size_t print_listint_safe(const listint_t *head)
{
const listint_t *slow, *fast;
size_t count;

slow = head;
fast = head;
count = 0;

while (slow != NULL && fast != NULL && fast->next != NULL)
{
printf("[%p] %d\n", (void *)slow, slow->n);
count++;
slow = slow->next;
fast = fast->next->next;

if (slow == fast)
{
printf("-> [%p] %d\n", (void *)slow, slow->n);
break;
}
}

if (slow == NULL || fast == NULL || fast->next == NULL)
{
while (head != NULL)
{
printf("[%p] %d\n", (void *)head, head->n);
count++;
head = head->next;
}
}

return (count);
}


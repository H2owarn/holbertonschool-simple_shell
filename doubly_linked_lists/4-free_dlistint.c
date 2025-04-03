#include <stdlib.h>
#include "lists.h"
/**
 * free_dlistint - Frees a dlistint_t doubly linked list.
 * @head: Pointer to the head of the doubly linked list.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

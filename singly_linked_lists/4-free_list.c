#include <stdlib.h>
#include "lists.h"
/**
 * free_list - Frees a list_t linked list.
 * @head: Pointer to the head of the linked list.
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->str);
		free(temp);
	}
}

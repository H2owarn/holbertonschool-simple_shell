#include <stdlib.h>
#include "lists.h"
/**
 * delete_dnodeint_at_index - Deletes the node at a given index in a
 * dlistint_t doubly linked list.
 * @head: Double pointer to the head of the linked list.
 * @index: The index of the node to delete, starting at 0.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistiny_t *temp;
	unsigned int count = 0;

	if (!head || !*head)
		return (-1);
	temp = *head;
	if (index == 0)
	{
		*head = temp->next;
		if (*head)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}
	while (temp && count < index)
	{
		temp = temp->next;
		count++;
	}
	if (!temp)
		return (-1);
	if (temp->next)
		temp->next->prev = temp->prev;
	if (temp->prev)
		temp->prev->next = temp->next;
	free(temp);
	return (1);
}

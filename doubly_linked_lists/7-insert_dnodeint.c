#include <stdlib.h>
#include "lists.h"
/**
 * insert_dnodeint_at_index - Inserts a new node at a specific index
 * in a doubly linked list.
 * @h: Double pointer to the head of the doubly linked list.
 * @idx: Index where the new node should be added (starts at 0).
 * @n: Integer value to store in the new node.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *temp;
	unsigned int count = 0;

	if (idx == 0)
		return (add_dnodeint(h, n));
	temp = *h;
	while (temp && count < idx - 1)
	{
		temp = temp->next;
		count++;
	}
	if (!temp ||
			(temp->next == NULL && count < idx - 1))
	{
		return (NULL);
	}
	if (temp->next == NULL
			return (add_dnodeint_end(h, n));
			new_node = malloc(sizeof(dlistint_t));
			if (!new_node)
				return (NULL);
				new_node->n = n;
				new_node->next = temp->next;
				new_node->prev = temp;
				if (temp->next)
					temp->next->prev = new_node;
					temp->next = new_node;
					return (new_node);
}

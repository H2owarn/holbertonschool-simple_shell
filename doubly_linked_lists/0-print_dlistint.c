#include <stdio.h>
#include "lists.h"
/**
 * print_number - Prints an integer using _putchar.
 * @n: The integer to print.
 */
void print_number(int n)
{
	unsigned int num = n;

	if (n < 0) /* Handle negative numbers */
	{
		_putchar('-');
		num = -n;
	}
	if (num / 10) /* Recursively print digits */
		print_number(num / 10);
	_putchar((num % 10) + '0'); /* Print the last digit */
}
/**
 * print_dlistint - Prints all the elements of a dlistint_t list.
 * @h: Pointer to the head of the doubly linked list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;

	while (h)
	{
	print_number(h->n)
	_putchar('\n');
	count++;
	h = h->next;
	}
	return (count);
}

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
#include <stddef.h>
/**
 * print_number - Prints an integer using _putchar.
 * @n: The integer to print.
 */
void print_number(int n)
{
	unsigned int num = n;

	if (n < 0)
	{
		num = -n;
	}
	if (num / 10)
		print_number(num / 10);
	_putchar((num % 10) + '0');
}
/**
 * print_string - Prints a string using _putchar.
 * @str: The string to print. If NULL, prints "(nil)".
 */
void print_string(const char *str)
{
	if (!str)
		str = "(nil)";
	while (*str)
	{
		_putchar(*str);
		str++;
	}
}
/**
 * print_list - Prints a singly linked list using _putchar.
 * @h: The head of the linked list.
 *
 * Return: The number of nodes.
 */
size_t print_list(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		print_string("[");
		print_number(h->len);
		print_string("]");
		print_string(h->str);
		_putchar('\n');
		h = h->next;
		count++;
	}
	return (count);
}

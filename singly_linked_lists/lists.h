#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H
#include <stddef.h>
/**
 * struct list_s - Singly linked list node
 * @str: String data stored in the node (malloc'ed string)
 * @len: Length of the string
 * @next: Pointer to the next node in the list
 *
 * Description: This structure represents a node in a singly linked list,
 * where each node contains a string, its length
 * and a pointer to the next node.
 */
typedef struct list_s
{
	char *str;               /* String - malloc'ed */
	unsigned int len;        /* Length of the string */
	struct list_s *next;     /* Points to the next node */
} list_t;

/**
 * print_list - Prints all elements of a singly linked list
 * @h: Pointer to the head of the linked list
 *
 * Return: Number of nodes in the list
 */
size_t print_list(const list_t *h);
/**
 * print_number - Prints an integer using _putchar
 * @n: The integer to be printed
 */
void print_number(int n);           /* Prints an integer using _putchar */
/**
 * print_string - Prints a string using _putchar
 * @str: The string to be printed. If NULL, prints "(nil)".
 */
void print_string(const char *str); /* Prints a string using _putchar */
/**
 * _putchar - Prints a single character to stdout
 * @c: The character to print
 *
 * Return: 1 on success, -1 on failure
 */
int _putchar(char c);               /* Prints a single character */
/**
 * list_len - returns the total number of nodes
 * @h: current node
 * Return:stirng
 */
size_t list_len(const list_t *h);
#endif /* VARIADIC_FUNCTIONS_H */

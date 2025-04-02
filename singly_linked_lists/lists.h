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

/* Function prototypes */
size_t print_list(const list_t *h);
void print_number(int n);           /* Prints an integer using _putchar */
void print_string(const char *str); /* Prints a string using _putchar */
int _putchar(char c);               /* Prints a single character */

#endif /* VARIADIC_FUNCTIONS_H */

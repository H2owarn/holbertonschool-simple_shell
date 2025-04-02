#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H
#include <stddef.h>

/* Structure for a singly linked list */
typedef struct list_s
{
    char *str;               /* String - malloc'ed */
    unsigned int len;        /* Length of the string */
    struct list_s *next;     /* Points to the next node */
} list_t;

/* Function prototypes */
size_t print_list(const list_t *h); /* Prints the linked list and returns number of nodes */
void print_number(int n);           /* Prints an integer using _putchar */
void print_string(const char *str); /* Prints a string using _putchar */
int _putchar(char c);               /* Prints a single character */

#endif /* VARIADIC_FUNCTIONS_H */

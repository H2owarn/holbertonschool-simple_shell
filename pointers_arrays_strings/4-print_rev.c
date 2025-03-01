#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
/**
 * print_rev -  prints a string
 * @s: Pointer to an integer that will be updated.
 *
 * Return: s
 */
void print_rev(char *s)
{
int len = strlen(s);
int i;
for (i = len - 1; i >= 0; i = i - 1)
{
_putchar(s[i]);
}
_putchar('\n');
}

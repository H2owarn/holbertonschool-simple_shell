#include "main.h"
/**
 * _print_rev_recursion - print chars
 * @s: chars
 *
 * Return: s
 *
 */
void _puts_recursion(char *s)
{
if (*s == '\0')
{
_putchar('\n');
return;
}
_putchar(*s);
_puts_recursion(s + 1);
}

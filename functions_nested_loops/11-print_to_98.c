#include "main.h"
#include <stdio.h>
/**
 * print_to_98  - pritn to 98
 *
 * print_number - Prints the negative sign and converts the number to positive.
 * @n : number
 *
 * Return: ...
 */
void print_number(int n)
{
if (n < 0)
{
_putchar('-');
n = -n;
}
if (n / 10)
{
print_number(n / 10);
}
_putchar((n % 10) + '0');
}
void print_to_98(int n)
{
if (n <= 98)
{
for (; n <= 98; n = n + 1)
{
print_number(n);
if (n != 98)
{
_putchar(',');
_putchar(' ');
}
}
}
else
{
for (; n >= 98; n = n - 1)
{
print_number(n);
if (n != 98)
{
_putchar(',');
_putchar(' ');
}
}
}
_putchar('\n');
}

#include "main.h"
/**
 *print_last_digit - print last digit
 *@n: The character to be checked.
 *
 * Return: int n
 */
int print_last_digit(int n)
{
int last;
last = n % 10;
if (last < 0)
{
last = last * -1;
}
_putchar (last + '0');
return (last);
}

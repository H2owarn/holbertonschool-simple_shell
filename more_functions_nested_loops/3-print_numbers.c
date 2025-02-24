#include "main.h"
#include <stdio.h>
/**
 *print_numbers - prints the numbers, from 0 to 9
 *
 *
 *
 *Return: n
 */
void print_numbers(void)
{
int n;
for ( n = 0 ; n <= 9 ; n = n + 1)
{
_putchar(n + '0');
}
_putchar('\n');
}

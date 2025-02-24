#include "main.h"
#include <stdio.h>
/**
 *print_most_numbers - prints the numbers, from 0 to 9.
 *@n : number 
 *
 *
 *
 *Return: n
 */
void print_most_numbers(void)
{
int n;
for (n = 0; n <= 9; n = n + 1 )
if (n != 2 && n != 4)
{
_putchar(n + '0');
}
_putchar('\n');
}

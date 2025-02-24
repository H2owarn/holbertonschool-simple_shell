#include "main.h"
#include <stdio.h>
/**
 *print_line - draws a straight line in the terminal.
 *@n: number
 *Return: 0
 */
void print_line(int n)
{
int i;
for (i = 0; i < n; i = i + 1)
{
_putchar('_');
}
_putchar('\n');
}

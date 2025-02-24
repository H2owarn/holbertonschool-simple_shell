#include "main.h"
#include <stdio.h>
/**
 *print_diagonal - draws a diagonal line on the terminal.
 *@n: number
 *Return: 0
 */
void print_diagonal(int n)
{
int i;
if (n > 0)
{
for (i = 0; i < n;i = i + 1)
{
_putchar('\\');
_putchar('\n');
}
_putchar('\n');
}
else
{
_putchar('\n');	
}
}

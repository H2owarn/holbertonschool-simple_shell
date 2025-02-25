#include "main.h"
#include <stdio.h>
/**
 *print_square - prints a square
 *@size : number
 *Return: 0
 */
void print_square(int size)
{
if (size == 0)
{
_putchar(' ');
_putchar('\n');
}
else
{
int i;
for (i = 0; i < size; i = i + 1)
{
int j;
for (j = 0; j < size; j = j + 1)
{
_putchar('#');
}
_putchar('\n');
}
}
}

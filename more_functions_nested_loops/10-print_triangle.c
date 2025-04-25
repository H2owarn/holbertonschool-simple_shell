#include "main.h"
#include <stdio.h>
/**
 *print_triangle - prints a triangle
 *@size : number
 *Return: 0
 */
void print_triangle(int size)
{
if (size <= 0)
{
_putchar('\n');
return;
}
else
{
int i;
for (i = 0; i < size; i = i + 1)
{
int j;
for (j = 0; j < size; j = j + 1)
{
if (j < size - i - 1)
{
_putchar(' ');
}
else
{
_putchar('#');
}
}
_putchar('\n');
}
}
}

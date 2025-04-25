#include "main.h"
/**
  * times_table - Prints the 9 times table, starting with 0
  *
  * Return: empty output
  */
void times_table(void)
{
int i, j, times;
for (i = 0; i <= 9; i++)
{
for (j = 0; j <= 9; j++)
{
times = i * j;
if (j != 0)
{
_putchar(',');
_putchar(' ');
}
if (times < 10 && j != 0)
{
_putchar(' ');
}
if (times >= 10)
{
_putchar((times / 10) + '0');
}
_putchar((times % 10) + '0');
}
_putchar('\n');
}
}

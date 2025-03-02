#include "main.h"
#include <stdio.h>
/**
 * puts_half -  prints a reverses a string.
 * @str: Pointer to an integer that will be updated.
 *
 * Return: *str
 */
void puts_half(char *str)
{
int len = 0;
int i, start;
while (str[len] != '\0')
{
len = len + 1;
}
if (len % 2 == 0)
{
start = len / 2;
}
else
{
start = (len + 1) / 2;
}
for (i = start; i < len; i = i + 1)
{
_putchar(str[i]);
}
_putchar('\n');
}

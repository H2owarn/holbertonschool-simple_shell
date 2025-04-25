#include "main.h"
#include <stdio.h>
/**
 * puts2 -  prints a reverses a string.
 * @str: Pointer to an integer that will be updated.
 *
 * Return: *str
 */
void puts2(char *str)
{
int i = 0;
while (str[i] != '\0')
{
if (i % 2 == 0)
{
_putchar(str[i]);
}
i = i + 1;
}
_putchar('\n');
}

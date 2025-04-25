#include "main.h"
#include <unistd.h>
#include <stdio.h>
/**
 * _puts -  prints a string
 * @str: Pointer to an integer that will be updated.
 *
 * Return: str
 */
void _puts(char *str)
{
while (*str)
{
write(1, str, 1);
str = str + 1;
}
_putchar('\n');
}

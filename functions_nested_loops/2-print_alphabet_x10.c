#include <stdio.h>
#include "main.h"
/**
 * print_alphabet_x10 - print 10 time
 *
 * Return: void
 */
void print_alphabet_x10(void)
{
int i = 0;
while (i <= 9)
{
char ch;
for (ch = 'a'; ch <= 'z'; ch = ch + 1)
{
_putchar(ch);
}
_putchar('\n');
i = i + 1;
}
}

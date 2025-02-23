#include <stdio.h>
#include "main.h"
/**
 * print_alphabet - make the alphabet
 *
 * Return: Always 0.
 */
void print_alphabet(void)
{
char ch;
for (ch = 'a'; ch <= 'z'; ch = ch + 1)
{
_putchar(ch);
}
_putchar('\n');
}

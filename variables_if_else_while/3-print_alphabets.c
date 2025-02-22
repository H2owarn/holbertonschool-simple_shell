#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry point
 *
 * This function prints a string to the standard output.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
char ch, chl;
for (ch = 'a' ; ch <= 'z' ; ch = ch + 1)
putchar(ch);
for (chl = 'A' ; chl <= 'Z' ; chl = chl + 1)
putchar(chl);
putchar('\n');
return (0);
}

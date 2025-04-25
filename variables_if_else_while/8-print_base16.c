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
char ch;
int n = 0;
for (n = 0 ; n  <= 9 ; n = n + 1)
putchar('0' + n);
for (ch = 'a' ; ch <= 'f' ; ch = ch + 1)
putchar(ch);
putchar('\n');
return (0);
}

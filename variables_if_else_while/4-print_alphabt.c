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
char ch = 'a';
while (ch != ('z' + 1))
{
if (ch != 'e' && ch != 'q')
{
putchar(ch);
}
ch = ch + 1;
}
putchar('\n');
return (0);
}

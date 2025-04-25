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
char ch = 'z';
for (ch = 'z'; ch >= 'a'; ch = ch - 1)
putchar(ch);
putchar('\n');
return (0);
}

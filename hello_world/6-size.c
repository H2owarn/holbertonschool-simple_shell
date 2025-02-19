#include <stdio.h>

/**
 * main - Entry point
 *
 * This function prints a string to the standard output.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
char c;
int i;
long l; 
long long int lln;
float f;
printf("Size of a char: %lu byte(s)\n",(unsigned long)sizeof(c));
printf("Size of an int: %lu byte(s)\n",(unsigned long)sizeof(i));
printf("Size of a long int: %lu byte(s)\n",(unsigned long)sizeof(l));
printf("Size of a long long int: %lu byte(s)\n",(unsigned long)sizeof(lln));
printf("Size of a float: %lu byte(s)\n",(unsigned long)sizeof(f));
return (0);
}

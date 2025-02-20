#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - Entry point
 *
 * This function prints a string to the standard output.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
int digit;
int n;
srand(time(0));
digit  = rand() - RAND_MAX / 2;
n = digit % 10;
if (n > 5)
printf("Last digit of %d is %d and is greater than 5\n", digit, n);
if (n != 0 && n < 6)
printf("Last digit of %d is %d and is less than 6 and not 0\n", digit, n);
if (n == 0)
printf("Last digit of %d is %d and is zero\n", digit, n);
return (0);
}

#include "main.h"
#include <stdio.h>
/**
 *more_numbers - prints 10 times  0 to 14.
 *
 *Return: n
 */
void more_numbers(void)
{
int i = 0;
while (i <= 9)
{
int n;
for (n = 0; n <= 14; n = n + 1)
{
if (n >= 10)
_putchar((n / 10) + '0');
_putchar((n % 10) + '0');
}
_putchar('\n');
i = i + 1;
}
}

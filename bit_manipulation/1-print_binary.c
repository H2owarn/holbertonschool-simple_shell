#include <stdio.h>
#include "main.h"
/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to convert and print in binary.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
	int leading_zero = 1;

	while (mask > 0)
	{
		if (n & mask)
		{
			leading_zero = 0;
			_putchar ('1');
		}
		else if (!leading_zero)
		{
			_putchar ('0');
		}
		mask >>= 1;
	}
	if (leading_zero)
	{
		_putchar('0');
	}
}

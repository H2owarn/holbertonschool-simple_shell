#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"
#include <unistd.h>
/**
 * print_string - Prints a string using _putchar.
 * @str: The string to print.
 */
void print_string(const char *str)
{
	while (str && *str)
	{
		_putchar(*str);
		str++;
	}
}
/**
 * print_number - Prints an integer using _putchar.
 * @n: The integer to print.
 */
void print_number(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	if (n / 10)
	{
		print_number(n / 10);
	}
	_putchar((n % 10) + '0');
}
/**
 * print_numbers - Prints numbers, followed by a new line.
 * @separator: The string to be printed between numbers.
 * @n: The number of integers passed to the function.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;

	va_start(args, n);
	for (i = 0; i < n; i = i + 1)
	{
		print_number(va_arg(args, int));
		if (separator && i < n - 1)
		{
			print_string(separator);
		}
	}
	va_end(args);
	_putchar('\n');
}

#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"
/**
 * print_string - Prints a string using _putchar.
 * @str: The string to print. Prints "(nil)" if the string is NULL.
 */
void print_string(const char *str)
{
if (!str)
{
print_string("(nil)");
return;
}
while (*str)
{
_putchar(*str++);
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
 * print_all - Prints anything based on the format.
 * @format: A list of types
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	char *str, *sep = "";

	va_start(args, format);
	while (format && format[i])
	{
		switch (format[i])
		{
			case 'c':
				_putchar(*sep);
				_putchar(va_arg(args, int));
				break;
			case 'i':
				_putchar(*sep);
				print_number(va_arg(args, int));
				break;
			case 'f': {
					  double f = va_arg(args, double);
					  int whole = (int)f;
					  int decimal = (int)((f - whole) * 1000000);

					 _putchar(*sep);
					  print_number(whole);
					  _putchar('.');
					  print_number(decimal);
break;
}
			case 's':
			_putchar(*sep);
			str = va_arg(args, char *);
			print_string(str ? str : "(nil)");
break;
		}
		sep = ", ";
		i++;
	}
	va_end(args);
	_putchar('\n');
}

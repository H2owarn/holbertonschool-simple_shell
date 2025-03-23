#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * print_number - prints an integer using _putchar
 * @n: The integer to print
 *
 * Return: Nothing
 */
void print_number(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	if (n / 10)
		print_number(n / 10);

	_putchar((n % 10) + '0');
}
/**
 * main- Performs simple operations
 * @argc: Number
 * @argv: Array
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;
	int (*operation)(int, int);

	if (argc != 4)
	{
		write(1, "Error\n", 6);
		exit(98);
	}
	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);
	operation = get_op_func(argv[2]);
	if (operation == NULL)
	{
		write(1, "Error\n", 6);
		exit(99);
	}
	result = operation(num1, num2);
	print_number(result);
	_putchar('\n');
	return (0);
}

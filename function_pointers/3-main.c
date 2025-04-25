#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
	char buffer[12];
	int len;

	if (argc != 4)
	{
		write(1, "Error\n", 6);
		exit(98);
	}

	operation = get_op_func(argv[2]);
	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);
	if (!operation)
	{
		write(1, "Error\n", 6);
		exit(99);
	}
	result = operation(num1, num2);
	len = sprintf(buffer, "%d\n", result);
	write(1, buffer, len);
	return (0);
}

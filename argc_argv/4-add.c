#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
/**
 * is_number - check if it string
 *
 * @str : string
 *
 * Return: 0 if it string 1 if all digit
 *
 */
int is_number(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0);
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str = str + 1;
	}
	return (1);
}
/**
 * main - print number of arguments
 * @argc: number
 * @argv: char
 *
 *
 * Return: multiple number
 */
int main(int argc, char *argv[])
{
	int sum = 0, i;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}
	for (i = 1; i < argc; i = i + 1)
	{
		if (!is_number(argv[i]))
		{
			printf("Error\n");
			return (1);
		}
		sum += atol(argv[i]);
	}
	printf("%d\n", sum);
	return (0);
}

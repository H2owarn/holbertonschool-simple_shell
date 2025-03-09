#include <stdlib.h>
#include <stdio.h>
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
	int n1, n2;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	n1 = atoi(argv[1]);
	n2 = atoi(argv[2]);
	printf("%d\n", n1 * n2);
	return (0);
}

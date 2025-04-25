#include <stdlib.h>
#include <stdio.h>
/**
 * main - print number of arguments
 * @argc: number
 * @argv: void
 *
 *
 * Return: argv - 1
 */
int main(int argc, char *argv[])
{
	(void)argv;
	printf("%d\n", argc - 1);
	return (0);
}

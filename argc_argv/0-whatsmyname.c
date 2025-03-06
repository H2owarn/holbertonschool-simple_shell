#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * main - print its name
 *
 * Return : names
 *
 */
int main(int argc, char* argv[])
{
	int i;
	for(i = 0; i < argc; i = i + 1)
	printf("%s\n", argv[i]); 
	return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * create_array -  creates an array of chars
 * @size: size of char
 * @c : char
 *
 * Return : NULL of size = 0 or fails  return the array
 */
char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int i;

	if (size == 0)
		return (NULL);

	array = malloc(size);
	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i = i + 1)
		array[i] = c;
	return (array);
}


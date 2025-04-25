#include <stddef.h>
#include "function_pointers.h"
/**
 * int_index - searches for an integer in an array
 * @array: the array of integers
 * @size: the number
 * @cmp: pointer to the comparison
 *
 * Return: the index of the first matching element
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL || size <= 0)
		return (-1);
	for (i = 0; i < size; i = i + 1)
	{
		if (cmp(array[i]) != 0)
			return (i);
	}
	return (-1);
}

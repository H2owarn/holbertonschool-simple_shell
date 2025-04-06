#include "main.h"
/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: The number to be evaluated.
 * @index: The index of the bit to retrieve, starting from 0.
 *
 * Return: The value of the bit (0 or 1), or -1 if an error occurred.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}
	return ((n & (1UL << index)) ? 1 : 0);
}

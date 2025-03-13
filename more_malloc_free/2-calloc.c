#include <stdio.h>
#include <string.h>
#include "main.h"
#include <stdlib.h>
/**
 * *_calloc - Allocates memory.
 *
 * @nmemb : number of elements in the array.
 * @size : size of each element in bytes
 *
 * Return : Pointer.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	unsigned int total_size, i;
	unsigned char *byte_ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	byte_ptr = (unsigned char *)ptr;
	for (i = 0; i < total_size; i = i + 1)
	{
		byte_ptr[i] = 0;
	}
	return (ptr);
}

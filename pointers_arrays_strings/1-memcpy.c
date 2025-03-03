#include "main.h"
#include <stddef.h>
/**
 * _memcpy - copies memory area
 * @dest : destination memory area
 * @src: source memory area
 * @n : number of bytes to copy
 *
 * Return: (dest)
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
unsigned char *d = (unsigned char *)dest;
const unsigned char *s = (const unsigned char *)src;
while (n--)
{
*d++ = *s++;
}
return (dest);
}

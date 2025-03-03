#include "main.h"
#include <stdio.h>
/**
 * *_memset - fills memory with a constant byte.
 * @s:memory area
 * @b:constant byte
 * @n: memory area pointed to
 * Return: s
 */
char *_memset(char *s, char b, unsigned int n)
{
unsigned char *ptr = (unsigned char *)s;
while (n--)
{
*ptr++ = (unsigned char)b;
}
return (s);
}

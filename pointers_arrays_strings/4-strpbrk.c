#include "main.h"
#include <stddef.h>
/**
 * _strpbrk  - called with s and f as arguments.
 * @s: the main string
 * @accept: the string containing the characters to match
 *
 * Return: a pointer to the first occurrence in s of the bytes in accept
 *
 */
char *_strpbrk(char *s, char *accept)
{
int i, j;
for (i = 0; s[i] != '\0'; i = i + 1)
{
for (j = 0; accept[j] != '\0'; j = j + 1)
{
if (s[i] == accept[j])
{
return (&s[i]);
}
}
}
return (NULL);
}

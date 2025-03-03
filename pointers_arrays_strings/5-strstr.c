#include "main.h"
#include <stddef.h>
/**
 * _strstr - locates a substring
 * @haystack: the main string to be searched
 * @needle: the substring to find
 *
 * Return: a pointer
 */
char *_strstr(char *haystack, char *needle)
{
char *h, *n;
while (*haystack)
{
h = haystack;
n = needle;
while (*n && *h == *n)
{
h = h + 1;
n = n + 1;
}
if (*n == '\0')
{
return (haystack);
}
haystack = haystack + 1;
}
return (NULL);
}

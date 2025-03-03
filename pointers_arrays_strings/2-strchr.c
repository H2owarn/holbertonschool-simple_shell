#include "main.h"
/**
 * _strchr - locates a character
 * @s:pointer of c or NULL
 * @c:the string
 *
 * Return: s
 *
 */
char *_strchr(char *s, char c)
{
while (*s != '\0')
{
if (*s == c)
{
return (s);
}
s = s + 1;
}
if (*s == c)
{
return (s);
}
return (NULL);
}

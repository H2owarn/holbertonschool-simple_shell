#include "main.h"
#include <stdio.h>
#include <unistd.h>
/**
 * *_strcpy - copies the string pointed to by src
 * @src :  string pointed
 * @dest : stirng
 *
 * Return: src
 */
char *_strcpy(char *dest, char *src)
{
char *ptr = dest;
while (*src)
{
*dest = *src;
dest = dest + 1;
src = src + 1;
}
*dest = '\0';
return (ptr);
}

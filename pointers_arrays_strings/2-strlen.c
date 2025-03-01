#include "main.h"
#include <stdio.h>
/**
 * _strlen - returns the length of a string.
 * @s: Pointer to an integer that will be updated.
 * 
 *
 * Description: This function returns the length of a string.
 */
int _strlen(char *s)
{
size_t len = 0;
while (s[len] != '\0')
{
len = len + 1;
}
return len;
}

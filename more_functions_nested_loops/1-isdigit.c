#include "main.h"
#include <stdio.h>
/**
 *_isdigit - checks for digit character.
 *@c: The character to check
 *
 *Return: 1 if c is digit, 0 otherwise
 */
int _isdigit(int c)
{
if (c >= '0' && c <= '9')
{
return (1);
}
else
{
return (0);
}
}


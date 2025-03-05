#include "main.h"
#include <stdio.h>
#include <math.h>
/**
 * _pow_recursion - return x pow y
 * @x: number
 * @y: number
 *
 * Return: result
 */
int _pow_recursion(int x, int y)
{
if (y < 0)
return (-1);
if (y == 0)
return (1);
return (x * _pow_recursion(x , y - 1));
}

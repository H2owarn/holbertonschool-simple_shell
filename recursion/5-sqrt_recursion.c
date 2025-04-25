#include "main.h"
#include <stdio.h>
/**
 * sqrt_guess - guess number
 * @n : number
 * @guess : x * x = n
 *
 * Return: guess number
 */
int sqrt_guess(int n, int guess)
{
if (guess * guess == n)
return (guess);
if (guess * guess > n)
return (-1);
return (sqrt_guess(n, guess + 1));
}
/**
 * _sqrt_recursion - calculates the natural square root of a number
 * @n: the number to find the square root of
 *
 * Return: the natural square root of n, or -1 if n does not have one
 */
int _sqrt_recursion(int n)
{
if (n < 0)
return (-1);
return (sqrt_guess(n, 0));
}

#include <stdio.h>
#include "main.h"
/**
 * is_prime - check if is a prime number
 * @i : 2
 * @n : number
 *
 * Return: 1 if is prime, 0 if otherwise
 */
int is_prime(int n, int i)
{
if (i * i > n)
return (1);
if (n % i == 0)
return (0);
return (is_prime(n, i + 1));
}
/**
 * is_prime_number - check if is prime
 * @n : number
 *
 * Return: 1 if is prime, 0 if otherwise
 *
 */
int is_prime_number(int n)
{
if (n <= 1)
return (0);
return (is_prime(n, 2));
}

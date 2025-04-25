#include "main.h"
#include <stdio.h>
#include <unistd.h>
/**
 * print_array -  prints a string.
 * @a: Pointer to an integer that will be updated.
 * @n: integer that will be updated.
 * Return: *a , n
 */
void print_array(int *a, int n)
{
int i;
for (i = 0; i < n; i = i + 1)
{
printf("%d", a[i]);
if (i < n - 1)
{
printf(", ");
}
}
printf("\n");
}


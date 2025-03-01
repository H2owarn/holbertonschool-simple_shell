#include "main.h"
#include <stdio.h>
/**
 * swap_int - swaps the values of two integers.
 * @a: Pointer to an integer that will be updated.
 * @b: Pointer to an integer that will be updated.
 *
 * Description: This function that swaps the values of two integers.
 */
void swap_int(int *a, int *b)
{
int sw = *a;
*a = *b;
*b = sw;
}

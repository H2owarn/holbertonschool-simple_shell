#include "main.h"
#include <stdio.h>
/**
 * reset_to_98 - Sets the value of the integer pointed to by n to 98.
 * @n: Pointer to an integer that will be updated.
 *
 * Description: This function takes a pointer to an integer and sets the value
 *              of the integer to 98. This is useful for updating the value of
 *              a variable from a different scope.
 */
void reset_to_98(int *n)
{
*n = 98;
}

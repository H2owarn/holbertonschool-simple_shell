#include <stddef.h>
#include "function_pointers.h"
/**
 * print_name - prints a name using a specified function
 * @name: name of the person
 * @f: function pointer to specify how to print the name
 *
 * Description: This function checks for null pointers and uses
 * the provided function to print the name in a specific format.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;
	f(name);
}

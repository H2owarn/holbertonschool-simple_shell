#include <stdio.h>
#include "dog.h"
/**
 * print_dog - print a stuct dog.
 * @d: pointrt to the syruct dog to print
 *
 *Description: If any element of d is NULL, it prints (nil).
 *              If d itself is NULL, it prints nothing.
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		return;
	printf("Name: %s\n", d->name ? d->name : "(nil)");
	printf("Age: %.1f\n", d->age);
	printf("Owner: %s\n", d->owner ? d->owner : "(nil)");
}

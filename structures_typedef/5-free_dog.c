#include <stdlib.h>
#include "dog.h"
/**
 * free_dog - Frees memory allocated for a dog_t struct.
 * @d: Pointer to the dog_t struct to free.
 *
 * Description: Frees the memory for the `name` and `owner` strings,
 *              as well as the dog_t struct itself.
 */
void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}

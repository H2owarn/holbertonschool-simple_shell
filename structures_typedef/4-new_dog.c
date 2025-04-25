#include <stdlib.h>
#include <string.h>
#include "dog.h"
/**
 * new_dog - Creates a new dog.
 * @name: Name of the dog.
 * @age: Age of the dog.
 * @owner: Owner of the dog.
 *
 * Return: Pointer to the new dog_t (success), or NULL if function fails.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog;
	char *new_name, *new_owner;
	int namel = 0, ownerl = 0, i;

	if (name == NULL || owner == NULL)
		return (NULL);
	while (name[namel] != '\0')
		namel++;
	while (owner[ownerl] != '\0')
		ownerl++;
	new_dog = malloc(sizeof(dog_t));
	if (new_dog == NULL)
		return (NULL);
	new_name = malloc(namel + 1);
	if (new_name == NULL)
	{
		free(new_dog);
		return (NULL);
	}
	for (i = 0; i <= namel; i++)
		new_name[i] = name[i];
	new_owner = malloc(ownerl + 1);
	if (new_owner == NULL)
	{
		free(new_name);
		free(new_dog);
		return (NULL);
	}
	for (i = 0; i <= ownerl; i++)
		new_owner[i] = owner[i];
	new_dog->name = new_name;
	new_dog->age = age;
	new_dog->owner = new_owner;
	return (new_dog);
}

#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * str_concat - concatenates two string
 * @s1 : char
 * @s2 : char
 *
 * Return: two string
 *
 */
char *str_concat(char *s1, char *s2)
{
	char *concat;
	int i, j, l1 = 0, l2 = 0;

	if (s1 != NULL)
	{
		while (s1[l1])
			l1 = l1 + 1;
	}
	if (s2 != NULL)
	{
		while (s2[l2])
			l2 = l2 + 1;
	}
	concat = malloc(sizeof(char) * (l1 + l2 + 1));
	if (concat == NULL)
		return (NULL);
	for (i = 0; i < l1; i = i + 1)
		concat[i] = s1[i];
	for (j = 0; j < l2; j = j + 1)
		concat[i + j] = s2[j];
	concat[i + j] = '\0';
	return (concat);
}


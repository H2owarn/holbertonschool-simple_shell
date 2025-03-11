#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str : string
 *
 * Return: pointer to a new string
 */
char *_strdup(char *str)
{
	int i, len = 0;
	char *result;

	if (str != NULL)
	{
		while (str[len])
			len = len + 1;
	}

	result = malloc(sizeof(char) * (len + 1));

	if (result  == NULL)
		return (NULL);
	for (i = 0; i < len; i = i + 1)
		result[i] = str[i];
	result[i] = '\0';

	return (result);
}

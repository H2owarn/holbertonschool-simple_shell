#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <string.h>
/**
 * string_nconcat - concatenates two strings
 *
 * @s1: first string
 * @s2: second string
 * @n: the number of bytes
 *
 *
 * Return: POinter
 *
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *re;
	unsigned int total_len, i, j;
	size_t len1 = 0, len2 = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (s1[len1] != '\0')
	{
		len1 = len1 + 1;
	}
	while (s2[len2] != '\0')
	{
		len2 = len2 + 1;
	}

	if (n >= len2)
		n = len2;
	total_len = len1 + n;
	re = malloc(total_len + 1);
	if (re == NULL)
		return (NULL);
	for (i = 0; i < len1; i = i + 1)
		re[i] = s1[i];
	for (j = 0; j < n; j = j + 1)
		re[i + j] = s2[j];
	re[i + j] = '\0';
	return (re);
}

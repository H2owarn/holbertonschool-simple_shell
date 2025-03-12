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
	unsigned int len1, len2, total_len, i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	len1 = strlen(s1);
	len2 = strlen(s2);

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

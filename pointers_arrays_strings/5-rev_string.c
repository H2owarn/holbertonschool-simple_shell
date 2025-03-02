#include "main.h"
#include <stdio.h>
/**
 * rev_string -  prints a reverses a string.
 * @s: Pointer to an integer that will be updated.
 *
 * Return: s
 */
void rev_string(char *s)
{
int len = 0, i;
char t;
while (s[len] != '\0')
{
len = len + 1;
}
for (i = 0;  i < len / 2; i = i + 1)
{
t = s[i];
s[i] = s[len - 1 - i];
s[len - 1 - i] = t;
}
}

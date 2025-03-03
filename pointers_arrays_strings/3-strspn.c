#include "main.h"
/**
 * _strspn - gets the length of a prefix substring.
 * @s: the main string
 * @accept: the sting
 *
 * Return:  the number of bytes
 */
unsigned int _strspn(char *s, char *accept)
{
unsigned int count = 0;
int i, j;
int found;
for (i = 0; s[i] != '\0'; i = i + 1)
{
found = 0;
for (j = 0; accept[j] != '\0'; j = j + 1)
{
if (s[i] == accept[j])
{
found = 1;
break;
}
}
if (found)
{
count = count + 1;
}
else
{
break;
}
}
return (count);
}

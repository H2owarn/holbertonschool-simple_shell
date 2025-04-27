#include <stddef.h>
#include <stdlib.h>
#include "shell.h"

/* _strlen */
int _strlen(const char *s)
{
    int len = 0;
    while (s && s[len])
        len++;
    return len;
}

/* _strchr */
char *_strchr(const char *s, char c)
{
    while (s && *s)
    {
        if (*s == c)
            return ((char *)s);
        s++;
    }
    return NULL;
}

/* _strdup */
char *_strdup(const char *s)
{
    char *copy;
    int len = _strlen(s);
    int i;

    copy = malloc(len + 1);
    if (!copy)
        return NULL;
    for (i = 0; i < len; i++)
        copy[i] = s[i];
    copy[i] = '\0';
    return copy;
}


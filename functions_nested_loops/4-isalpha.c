#include "main.h"
/**
 * _isalpha - check if is low or uppercase
 *@c: The character to be checked.
 *
 * Return: int c
 */
int _isalpha(int c)
{
return ((c >= 'a' && c <= 'z') ||  (c >= 'A' && c <= 'Z'));
}

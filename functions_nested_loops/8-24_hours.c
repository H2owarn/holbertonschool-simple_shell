#include "main.h"
/**
 *jack_bauer - prints every minute of the day of Jack Bauer
 *
 *
 * Return : ..
 */
void jack_bauer(void)
{
int h, m;
for (h = 0; h < 24; h = h + 1)
{
for (m = 0; m < 60; m = m + 1)
{
_putchar((h / 10) + '0');
_putchar((h % 10) + '0');
_putchar(':');
_putchar((m / 10) + '0');
_putchar((m % 10) + '0');
_putchar('\n');
}
}
}

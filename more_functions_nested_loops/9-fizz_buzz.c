#include <stdio.h>
/**
 *main - print i by 3 conditions
 *
 *
 *Return: 0
 */
int main(void)
{
int i;
for (i = 1; i <= 100; i = i + 1)
{
if (i % 3 == 0 && i % 5 == 0)
{
printf("FizzBuzz");
}
else if (i % 5 == 0)
{
printf("Buzz");
}
else if (i % 3 == 0)
{
printf("Fizz");
}
else
{
printf("%d", i);
}
printf(" ");
}
printf("\n");
return (0);
}

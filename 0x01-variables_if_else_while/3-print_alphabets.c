#include <stdio.h>
/**
 * main - print alphabet in lowercase
 * and then in uppercase followed by a new line
 *
 * Return: 0 on success
 */
int main(void)
{
int i;
for (i = 0; i < 26; i++)
{
	putchar('a' + i);
}
for (i =0; i < 26; i++)
{
	putchar('A' + i);
}
putchar('\n');
return (0);
}

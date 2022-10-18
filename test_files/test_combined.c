#include "main.h"
#include <stdio.h>
/**
 * main - Check code
 *
 * Return: Void
 */
int main(void)
{
	char *s;
	char *s2;
	char *s3;
	char *s4;
	char c;
	int i;
	int b;

	c = 'p';
	i = -123455;
	s = "I go to Jomo to buy some sweets.\n";
	s2 = "Mary had a little lamb.\n";
	s3 = "Humpty committed suicide.\n";
	s4 = "The longest day of the year, does not exist.\n";
	b = 89;
	_printf("asdfasdfas\n");
	printf("asdfasdfas\n");
	_printf("--------------\n\n\n");
	_printf("fasdf\n %s\n %c\n %s\n %s\n %s\n
	%i\n %b\n\n\n", s, c, s2, s3, s4, i, b);
	printf("fasdf\n %s\n %c\n %s\n %s\n %s\n %i\n\n\n", s, c, s2, s3, s4, i);
	_printf("--------------\n\n");
	_printf("%b\n", 98);
	_printf("--------------\n\n\n");
	return (0);
}

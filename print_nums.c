#include "main.h"

/**
 * print_number - prints a number send to this function
 * @list_arg: List of arguments
 * Return: The number of arguments printed
 */
int print_number(va_list list_arg)
{
	int n;
	int div;
	int len;
	unsigned int num;

	n  = va_arg(list_arg, int);
	div = 1;
	len = 0;

	if (n < 0)
	{
		len += write_output('-');
		num = n * -1;
	}
	else
		num = n;

	for (; num / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		len += write_output('0' + num / div);
		num %= div;
		div /= 10;
	}

	return (len);
}
/**
 * print_unsgined_number - Prints an unsigned number
 * @n: unsigned integer to be printed
 * Return: The amount of numbers printed
 */
int print_unsgined_number(unsigned int n)
{
	int div;
	int len;
	unsigned int num;

	div = 1;
	len = 0;

	num = n;

	for (; num / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		len += write_output('0' + num / div);
		num %= div;
		div /= 10;
	}

	return (len);
}


#include "main.h"

/**
 * print_char - Prints character
 * @list_arg: list of arguments
 * Return: Will return the amount of characters printed.
 */
int print_char(va_list list_arg)
{
	write_output(va_arg(list_arg, int));
	return (1);
}

/**
 * print_string - Prints a string
 * @list_arg: list of arguments
 * Return: Amount of characters printed.
 */
int print_string(va_list list_arg)
{
	int i;
	char *str;

	str = va_arg(list_arg, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		write_output(str[i]);
	return (i);
}

/**
 * print_percent - Prints a percent symbol
 * @list_arg: list of arguments
 * Return: Amount of characters printed.
 */
int print_percent(__attribute__((unused))va_list list_arg)
{
	write_output('%');
	return (1);
}

/**
 * print_integer - Prints an integer
 * @list_arg: list of arguments
 * Return: Amount of characters printed.
 */
int print_integer(va_list list_arg)
{
	int num_length;

	num_length = print_number(list_arg);
	return (num_length);
}

/**
 * unsigned_integer - Prints Unsigned integers
 * @list_arg: List of all of the argumets
 * Return: A count of the numbers
 */
int unsigned_integer(va_list list_arg)
{
	unsigned int num;

	num = va_arg(list_arg, unsigned int);

	if (num == 0)
		return (print_unsgined_number(num));

	if (num < 1)
		return (-1);
	return (print_unsgined_number(num));
}

#include "main.h"

/**
 * print_char - Prints a char
 * @list_arg: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list list_arg, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(list_arg, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/**
 * print_string - Prints a string
 * @list_arg: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list list_arg, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, count;
	char *str = va_arg(list_arg, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & SUBTRACT)
		{
			write(1, &str[0], length);
			for (count = width - length; count > 0; count--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (count = width - length; count > 0; count--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}

/**
 * print_percent - Prints a percent sign
 * @list_arg: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list list_arg, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(list_arg);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * print_int - Print int
 * @list_arg: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list list_arg, char buffer[],
	int flags, int width, int precision, int size)
{
	int count = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(list_arg, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[count--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[count--] = (num % 10) + '0';
		num /= 10;
	}

	count++;

	return (write_number(is_negative, count, buffer, flags, width, precision, size));
}

/**
 * print_binary - Prints an unsigned number
 * @list_arg: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list list_arg, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int num, dec, sum;
	unsigned int unsigned_array[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	num = va_arg(list_arg, unsigned int);
	dec = 2147483648; /* (2 ^ 31) */
	unsigned_array[0] = num / dec;
	for (count = 1; count < 32; count++)
	{
		dec /= 2;
		unsigned_array[count] = (num / dec) % 2;
	}
	for (count = 0, sum = 0, count = 0; count < 32; count++)
	{
		sum += unsigned_array[count];
		if (sum || count == 31)
		{
			char hold = '0' + unsigned_array[count];

			write(1, &hold, 1);
			count++;
		}
	}
	return (count);
}

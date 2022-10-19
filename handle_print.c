#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list_arg: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *ind, va_list list_arg, char buffer[],
	int flags, int width, int precision, int size)
{
	int count, unknow_len = 0, printed_chars = -1;
	sym_t sym_types[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'i', print_int},
		{'d', print_int},
		{'b', print_binary},
		{'u', print_unsigned},
		{'o', print_octal},
		{'x', print_hexadecimal},
		{'X', print_hexa_upper},
		{'p', print_pointer},
		{'S', print_non_printable},
		{'r', print_reverse},
		{'R', print_rot13string},
		{'\0', NULL}
	};
	for (count = 0; sym_types[count].sym != '\0'; count++)
		if (fmt[*ind] == sym_types[count].sym)
			return (sym_types[count].func(list_arg, buffer, flags, width, precision, size));

	if (sym_types[count].sym == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}

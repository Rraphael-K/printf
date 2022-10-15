#include "main.h"

/**
 * _printf - Handle symbol input and all parameters and print formated string
 * @format: Types of arguments passed in the function
 *
 * Return: Count of printed characters
 */
int _printf(const char *format, ...)
{
	/* integer to contain count of printed symbols */
	int printed_sym;
	/* array containing all sysmbols */
	symbol sym_list[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percentage}
	};
}

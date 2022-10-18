#include <stdarg.h>
#include "main.h"
#include <stdio.h>

/**
 * _printf - Receives the main string and all the necessary parameters
 * @format: String containing all the desired characters
 * Return: A total count of the characters printed
 */
int _printf(const char *format, ...)
{
	int printed_chars;
	symbols func_list[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_binary},
		{"r", print_reversed},
		{"R", rot13},
		{"u", unsigned_integer},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_heX},
		{NULL, NULL}
	};
	/* va_list holds info required by va_start, va_arg and va_end */
	va_list list_arg;
    /* if the format is NULL, return an error */
	if (format == NULL)
		return (-1);
    /* obtain the char entered required for formating */
	va_start(list_arg, format);
	/*Calling parser function*/
	printed_chars = parser(format, func_list, list_arg);
	va_end(list_arg);
	return (printed_chars);
}

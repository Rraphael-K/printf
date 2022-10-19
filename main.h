#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define SUBTRACT 1
#define ADD 2
#define ZERO 4
#define HASH 8
#define SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct symbols - Struct op
 *
 * @sym: The format.
 * @func: The function associated.
 */
struct symbols
{
	char sym;
	int (*func)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct sym sym_t - Struct op
 *
 * @sym: The format.
 * @: The function associated.
 */
typedef struct symbols sym_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i, va_list list_arg, char buffer[], int flags, int width, int precision, int size);

/* Print and string functions */
int print_char(va_list list_arg, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list list_arg, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list list_arg, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list list_arg, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list list_arg, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list list_arg, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list list_arg, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list list_arg, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list list_arg, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list list_arg, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int print_non_printable(va_list list_arg, char buffer[],
	int flags, int width, int precision, int size);

/* Funcion to print memory address */
int print_pointer(va_list list_arg, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list_arg);
int get_precision(const char *format, int *i, va_list list_arg);
int get_size(const char *format, int *i);

/*Function to print string in reverse*/
int print_reverse(va_list list_arg, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot13string(va_list list_arg, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char empty, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char empty, char extra_c, int empty_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

int printable(char);
int append_hex(char, char[], int);
int digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */

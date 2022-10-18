#ifndef PRINT_F
#define PRINT_F

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
* struct symbol - defines a structure for symbols and functions
*
* @sym: The operator
* @func: The function associated
*/
struct symbol
{
	char *sym;
	int (*func)(va_list);
};
typedef struct symbol symbols;

/*Main functions*/
int _printf(const char *format, ...);
int parser(const char *format, symbols func_list[], va_list list_arg);
int write_output(char);
/* use va_list to handle the stdarg macros */
int print_char(va_list);
int print_string(va_list);
int print_percent(va_list);
int print_integer(va_list);
int print_number(va_list);
int print_binary(va_list);
int print_reversed(va_list list_arg);
int rot13(va_list);
int unsigned_integer(va_list);
int print_octal(va_list list_arg);
int print_hex(va_list list_arg);
int print_heX(va_list list_arg);

/*Helper functions*/
unsigned int base_len(unsigned int, int);
char *reverse_string(char *);
void write_base(char *str);
char *_memcpy(char *dest, char *src, unsigned int n);
int print_unsgined_number(unsigned int);


#endif


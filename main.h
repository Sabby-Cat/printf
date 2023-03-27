#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

#define B_SIZE 1024
/**
 * struct fmt - create struct
 * @fmt: type specifier char
 * @fn: function
 */
typedef struct fmt
{
	char fmt;
	int (*fn)(va_list, char[]);
} fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i, va_list list, char buffer[]);
/****formats****/
int print_char(va_list list, char buffer[]);
int print_string(va_list list, char buffer[]);
int print_percent(va_list list, char buffer[]);
int print_int(va_list list, char buffer[]);
int print_binary(va_list list, char buffer[]);

/****custom****/
int print_reverse(va_list list, char buffer[]);
int print_rot13(va_list list, char buffer[]);

#endif

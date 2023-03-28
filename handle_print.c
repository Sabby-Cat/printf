#include "main.h"
/**
 * handle_print - decides which function(s) to call
 * @fmt: format
 * @i: position in fmt
 * @list: arg list
 * @buffer: buffer to print
 * Return: nr of chars printed
 */
int handle_print(const char *fmt, int *i, va_list list, char buffer[])
{
	int c_printed = -1, j, len = 0;
	fmt_t fmt_set[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'p', print_pointer}, {'S', print_unprintable}, {'r', print_reverse},
		{'R', print_rot13}, {'\0', NULL}
	};
	for (j = 0; fmt_set[j].fmt != '\0'; j++)
		if (fmt[*i] == fmt_set[j].fmt)
			return (fmt_set[j].fn(list, buffer));
	if (fmt_set[j].fmt == '\0')
	{
		if (fmt[*i] == '\0')
			return (-1);
		if (fmt[*i - 1] == ' ')
			len += write(1, " ", 1);
		len +=  write(1, &fmt[*i], 1);
		return (len);
	}
	return (c_printed);
}

#include "main.h"
void print_buffer(char buffer[], int *buff_s);

/**
 * _printf - prints things
 * @format: format list
 * Return: -1 if fails else nr of printed chars
 */
int _printf(const char *format, ...)
{
	int i, printed = 0;
	int buff_s = 0, c_count = 0;
	va_list list;
	char buffer[B_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_s++] = format[i];
			if (buff_s == B_SIZE)
				print_buffer(buffer, &buff_s);
			c_count++;
		}
		else
		{
			print_buffer(buffer, &buff_s);
			++i;
			printed = handle_print(format, &i, list, buffer);
			if (printed == -1)
				return (-1);
			c_count += printed;
		}
	}
	print_buffer(buffer, &buff_s);
	va_end(list);
	return (c_count);
}

/**
 * print_buffer - print buffer
 * @buffer: buffer to be printed
 * @buff_s: current size of buffer
 */
void print_buffer(char buffer[], int *buff_s)
{
	if (*buff_s > 0)
		write(1, &buffer[0], *buff_s);
	*buff_s = 0;
}

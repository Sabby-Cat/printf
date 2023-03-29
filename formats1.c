#include "main.h"
/**
 * print_unsigned - prints unsigned number
 * @list: arguments
 * @buffer: array
 * Return: nr of char
 */
int print_unsigned(va_list list, char buffer[])
{
	int i = B_SIZE - 2, c;
	unsigned long int num = va_arg(list, unsigned long int);


	if (num == 0)
		buffer[i--] = '0';

	buffer[B_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	c = B_SIZE - i - 1;
	return (write(1, &buffer[i], c));
}
/**
 * print_octal - prints octal nr
 * @list: args
 * @buffer: array
 * Return: nr chars printed
 */
int print_octal(va_list list, char buffer[])
{
	int i = B_SIZE - 2, c;
	unsigned long int num = va_arg(list, unsigned long int);

	if (num == 0)
		buffer[i--] = '0';

	buffer[B_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	i++;

	c = B_SIZE - i - 1;
	return (write(1, &buffer[i], c));
}
/**
 * print_upper_hex - prints upper case hexadeximal
 * @list: args
 * @buffer: array
 * Return: nr chars printed
 */
int print_upper_hex(va_list list, char buffer[])
{
	return (print_hexadecimal(list, "0123456789ABCDEF", buffer));
}
/**
 * print_lower_hex - prints lower case hexadeximal
 * @list: args
 * @buffer: array
 * Return: nr chars printed
 */
int print_lower_hex(va_list list, char buffer[])
{
	return (print_hexadecimal(list, "0123456789abcdef", buffer));
}
/**
 * print_hexadecimal - prints hexadeximal
 * @list: args
 * @map_to: char array for conversion
 * @buffer: array
 * Return: nr chars printed
 */
int print_hexadecimal(va_list list, char map_to[], char buffer[])
{
	int i = B_SIZE - 2, c;
	unsigned long int num = va_arg(list, unsigned long int);

	if (num == 0)
		buffer[i--] = '0';

	buffer[B_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	i++;
	c = B_SIZE - i - 1;
	return (write(1, &buffer[i], c));
}

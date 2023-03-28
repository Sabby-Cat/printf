#include "main.h"
/**
 * print_reverse - prints reverse string
 * @list: input varible list
 * @buffer: buffer to print
 * Return: nr of chars written
 */
int print_reverse(va_list list, char buffer[])
{
	int i, c;
	char *ret = va_arg(list, char *);
	char tmp;

	UNUSED(buffer);
	i = strlen(ret) - 1;
	if (ret == NULL)
		ret = "(null)";
	for (; i >= 0; i--)
	{
		tmp = ret[i];
		write(1, &tmp, 1);
		c++;
	}
	return (c);
}

/**
 * print_rot13 - prints rot13d string
 * @list: input varible list
 * @buffer: buffer to print
 * Return: nr of chars written
 */
int print_rot13(va_list list, char buffer[])
{
	int i, j, c = 0;
	char *ret = va_arg(list, char *), tmp;
	char r[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char o[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	UNUSED(buffer);
	if (ret == NULL)
		ret = "(null)";
	for (i = 0; ret[i] != '\0'; i++)
	{
		for (j = 0; o[j] != '\0'; j++)
		{
			if (ret[i] == o[j])
			{
				tmp = r[j];
				write(1, &tmp, 1);
				c++;
				break;
			}
		}
		if (!o[j])
		{
			tmp = ret[i];
			write(1, &tmp, 1);
			c++;
		}
	}
	return (c);
}
/**
 * print_unprintable - prints a string with unprinables added as \xhh
 * @list: list
 * @buffer: array
 * Return: nr printed
 */
int print_unprintable(va_list list, char buffer[])
{
	int i, o = 0;
	char *ret = va_arg(list, char *);

	if (ret == NULL)
		return (write(1, "(null)", 6));
	for (i = 0; ret[i] != '\0'; i++)
	{
		if (ret[i] >= 32 && ret[i] < 127)
			buffer[i + o] = ret[i];
		else
			o += add_hex(ret[i], buffer, i + o);
	}
	buffer[i + o] = '\0';
	return (write(1, buffer, i + o));
}

/**
 * add_hex - adds 2 dig hex code
 * @c: char
 * @buffer: array
 * @i: position
 * Return: nr printed
 */
int add_hex(char c, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (c < 0)
		c *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[c / 16];
	buffer[i] = map_to[c % 16];

	return (3);
}

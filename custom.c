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
	int i, j, c;
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

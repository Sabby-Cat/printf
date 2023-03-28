#include "main.h"
#include <stdlib.h>
/**
 * print_char - prints a char
 * @list: variable list
 * @buffer: buffer to print
 * Return: 1
 */
int print_char(va_list list, char buffer[])
{
	char c = va_arg(list, int);
	int i = 0;

	buffer[i++] = c;
	buffer[i] = '\0';
	return (write(1, &buffer[0], 1));
}

/**
 * print_string - prints a string
 * @list: variable list
 * @buffer: buffer to print
 * Return: len
 */
int print_string(va_list list, char buffer[])
{
	int len = 0;
	char *ret = va_arg(list, char *);

	UNUSED(buffer);
	if (ret == NULL)
		ret = "(null)";
	len = strlen(ret);
	return (write(1, ret, len));
}

/**
 * print_percent - prints %
 * @list: variable list
 * @buffer: buffer to print
 * Return: 1
 */
int print_percent(va_list list, char buffer[])
{
	UNUSED(list);
	UNUSED(buffer);
	return (write(1, "%%", 1));
}

/**
 * print_int - prints a number
 * @list: variable list
 * @buffer: buffer to print
 * Return: nr of chars printed
 */
int print_int(va_list list, char buffer[])
{
	int long n = va_arg(list, long int);
	unsigned long int num;
	int i = B_SIZE - 2, c = 0;
	int is_neg = 0;

	if (n == 0)
		buffer[i--] = '0';

	buffer[B_SIZE - 1] = '\0';
	num = labs(n);
	if (n < 0)
	{
		num = labs(n);
		is_neg = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	if (is_neg)
		buffer[i--] = '-';
	i++;
	c = B_SIZE - i - 1;
	return (write(1, &buffer[i], c));

}

/**
 * print_binary - prints binary nr
 * @list: variable list
 * @buffer: buffer to print
 * Return: nr of chars printed
 */
int print_binary(va_list list, char buffer[])
{
	unsigned int n, p, i, sum = 0;
	unsigned int a[32];
	int count = 0;

	UNUSED(buffer);
	n = va_arg(list, unsigned int);
	p = 2147483648;
	a[0] = n / p;
	for (i = 1; i < 32; i++)
	{
		p /= 2;
		a[i] = (n / p) % 2;
	}
	for (i = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char c = '0' + a[i];

			write(1, &c, 1);
			count++;
		}
	}
	return (count);
}

#include "main.h"
/**
 * print_pointer - prints pointer
 * @list: arguments
 * @buffer: array
 * Return: nr chars printed
 */
int print_pointer(va_list list, char buffer[])
{
	int i = B_SIZE - 2;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(list, void *);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[B_SIZE - 1] = '\0';

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[i--] = map_to[num_addrs % 16];
		num_addrs /= 16;
	}

	i++;

	buffer[--i] = 'x';
	buffer[--i] = '0';
	return (write(1, &buffer[i], B_SIZE - i - 1));
}

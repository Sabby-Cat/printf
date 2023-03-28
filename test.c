#include "main.h"
#include <stdio.h>
int main(void)
{
	int o = 15;
	int p = -15;
	long int k = p;

	printf("%d\n", 2147483646);
	int a = _printf("%d\n", o);
	int b = _printf("%d\n", -20);
	_printf("%d\n", -19);
	_printf("%d\n", -18);
	printf("%d   %d\n", a, b);
	return (0);
}

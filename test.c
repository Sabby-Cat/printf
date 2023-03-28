#include "main.h"
#include <stdio.h>
int main(void)
{
	int a = _printf("%d\n", 67);
	int b = _printf("%d\n", -67);
	printf("%d   %d\n", a, b);
	return (0);
}

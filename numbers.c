#include "main.h"

/**
 * convert - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: arg flags
 * @params: param struct
 *
 * Return: string
 */
char *convert(long int num, int base, int flags, params_t *params)
{
	static char *arr;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	arr = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = arr[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * print_unsigned - prints unsigned integer numbers
 * @ap: argument pointer
 * @params: the parameter struct
 *
 * Return: bytes printed
 */
int print_unsigned(va_list ap, params_t *params)
{
	unsigned long lo;

	if (params->l_modifier)
		lo = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		lo = (unsigned short int)va_arg(ap, unsigned int);
	else
		lo = (unsigned int)va_arg(ap, unsigned int);
	params->unsign = 1;
	return (print_number(convert(lo, 10, CONVERT_UNSIGNED, params), params));
}



/**
 * print_address - prints address
 * @ap: arg pointer
 * @params: the parameter struct
 *
 * Return: bytes printed
 */
int print_address(va_list ap, params_t *params)
{
	unsigned long int u = va_arg(ap, unsigned long int);
	char *str;

	if (!u)
		return (_puts("(nil)"));

	str = convert(u, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, params));
}

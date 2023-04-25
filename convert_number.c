#include "main.h"

/**
 * print_hex - prints unsigned hex numbers in lowercase.
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_hex(va_list ap, params_t *params)
{
	unsigned long lo;
	int c = 0;
	char *str;

	if (params->l_modifier)
		lo = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		lo = (unsigned short int)va_arg(ap, unsigned int);
	else
		lo = (unsigned int)va_arg(ap, unsigned int);

	str = convert(lo, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag_flag && lo)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * print_HEX - prints unsigned hex numbers in uppercase
 * @ap: the argument pointer
 * @params: the parameters struct.
 *
 * Return: bytes printed
 */
int print_HEX(va_list ap, params_t *params)
{
	unsigned long lo;
	int c = 0;
	char *str;

	if (params->l_modifier)
		lo = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		lo = (unsigned short int)va_arg(ap, unsigned int);
	else
		lo = (unsigned int)va_arg(ap, unsigned int);

	str = convert(lo, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && lo)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += print_number(str, params));
}
/**
 * print_binary - prints unsigned binary number.
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_binary(va_list ap, params_t *params)
{
	unsigned int i = va_arg(ap, unsigned int);
	char *str = convert(i, 2, CONVERT_UNSIGNED, params);
	int c = 0;

	if (params->hashtag_flag && i)
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));
}

/**
 * print_octal - prints unsigned octal numbers.
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_octal(va_list ap, params_t *params)
{
	unsigned long lo;
	char *str;
	int c = 0;

	if (params->l_modifier)
		lo = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		lo = (unsigned short int)va_arg(ap, unsigned int);
	else
		lo = (unsigned int)va_arg(ap, unsigned int);
	str = convert(lo, 8, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && lo)
		*--str = '0';
	params->unsign = 1;
	return (c += print_number(str, params));
}

#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of args
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int curri = *i + 1;
	int precision = -1;

	if (format[curri] != '.')
		return (precision);

	precision = 0;

	for (curri += 1; format[curri] != '\0'; curri++)
	{
		if (is_digit(format[curri]))
		{
			precision *= 10;
			precision += format[curri] - '0';
		}
		else if (format[curri] == '*')
		{
			curri++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curri - 1;

	return (precision);
}

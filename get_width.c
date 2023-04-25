#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of args
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curri;
	int width = 0;

	for (curri = *i + 1; format[curri] != '\0'; curri++)
	{
		if (is_digit(format[curri]))
		{
			width *= 10;
			width += format[curri] - '0';
		}
		else if (format[curri] == '*')
		{
			curri++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curri - 1;

	return (width);
}

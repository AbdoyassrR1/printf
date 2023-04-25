#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int curr = *i + 1;
	int SIZE = 0;

	if (format[curr] == 'l')
		SIZE = S_LONG;
	else if (format[curr] == 'h')
		SIZE = S_SHORT;

	if (SIZE == 0)
		*i = curr - 1;
	else
		*i = curr;

	return (SIZE);
}

#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: format string containing the characters and spcifiers
 *by Alex and Innocent
 * Return: length of the formatted output string
 *
 */
int _printf(const char *format, ...)
{
	int (*pfunc)(va_list, flags_t *);
	const char *new;
	va_lsit ap;
	flags_t flags = {0, 0, 0};

	register int count = 0;

	va_start(ap, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (new = format; *new; new++)
	{
		if (*new == '%')
		{
			new++;
			if (*new == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (get_flag(*new, &flags))
				new++;
			pfunc = get_print(*new);
			count += (pfunc)
				? pfunc(ap, &flags)
				: _printf("%%%c", *new);
		}
		else
			count += _putchar(*new);
	}
	_putchar(-1);
	va_end(ap);
	return (count);
}

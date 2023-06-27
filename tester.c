#include "main.h"

/**
 *_putchar -writes a single character c to the standard output stream
 *_printf - the main function
 *c-represents a single character that needs to be
 *written to the standard output stream
 *Return: Count of no of chars printed
 */

int _putchar(char c) {return write(1, &c, 1); }

int _printf(const char *format, ...)
{
	va_list arg;
	int count = 0;

	va_start(arg, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			if (*format == 'c')
			{
				int character = va_arg(arg, int);

				count += _putchar((char)character);
			}
		}
		else
		{
			count += _putchar(*format);
		}
		format++;

	}
	va_end(arg);
	return (count);
}

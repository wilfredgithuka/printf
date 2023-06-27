#include "main.h"

/**
 * print_char - Function to prints a char[c]
 * @x: List a of args given
 * @buffer: This is an array to handle the print characters
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Count of no of chars printed
 */

int print_char(va_list x, char buffer[], int flags, int width)
{
	char c = va_arg(x, int);

	return (handle_print_char(c, buffer, flags, width));
}

/**
 * print_string - Function to print a string[s]
 * @y: List of args given
 * @buffer: This is an array to handle the print characters.
 * Return: Count of no of strings printed
 */

int print_string(va_list y, char buffer[])
{
	int str_length = 0;
	char *str = va_arg(y, char *);

	UNUSED(buffer);

	while (str[str_length] != '\0')
		str_length++;

	return (write(1, str, str_length));
}

/**
 * print_pc - Prints a percent sign
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * Return: Number of chars printed
 */

int print_pc(va_list z, char buffer[])
{
	UNUSED(z);
	UNUSED(buffer);
	return (write(1, "%%", 1));
}



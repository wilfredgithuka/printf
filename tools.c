#include "main.h"

/**
 * print_char - Function to prints a char[c]
 * @x: List a of args given
 * Return: Count of no of chars printed
 */

int print_char(va_list x, char_buffer[])
{
	char c = va_arg(x, int);

	return (handle_char(c));
}

/**
 * print_string - Function to print a string[s]
 * @y: List of args given
 * Return: Count of no of strings printed
 */

int print_string(va_list y, char_buffer[])
{
	int str_length = 0, i;
	char *str = va_arg(types, char *);

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
	return (write(1, "%%", 1));
}



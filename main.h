#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int _printf(const char *format, ...);
int printf_char(va_list val);


/* Funtions to print chars and strings */
int print_char(va_list x, char buffer[]);
int print_string(va_list y, char buffer[]);
int print_pc(va_list z, char buffer[]);

#endif

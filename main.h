#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)

/* Some bit of Flags */

#define F_ZERO 4
#define F_MINUS 1

int _printf(const char *format, ...);

/* Funtions to print chars and strings */
int print_char(va_list x, char buffer[], int flags, int width);
int print_string(va_list y, char buffer[]);
int print_pc(va_list z, char buffer[]);
/* Tester*/
int _putchar(char c) {return write(1, &c, 1); }

/*Print handlers*/
/* width handler */
int handle_print_char(char c, char buffer[], int flags, int width);

#endif

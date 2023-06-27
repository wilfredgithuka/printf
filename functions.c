#include "main.h"

/************************* Print Character *************************/

int print_char(va_list args, char buffer[],
              int flags, int width, int precision, int size)
{
    char c = va_arg(args, int);

    return handle_write_char(c, buffer, flags, width, precision, size);
}

/************************* Print String *************************/

int print_string(va_list args, char buffer[],
                 int flags, int width, int precision, int size)
{
    char *str = va_arg(args, char *);
    int length = 0;

    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    if (str == NULL)
        str = "(null)";

    while (str[length] != '\0')
        length++;

    if (precision >= 0 && precision < length)
        length = precision;

    for (int i = 0; i < width - length; i++)
        write(1, " ", 1);

    return write(1, str, length);
}

/************************* Print Percent Sign *************************/

int print_percent(va_list args, char buffer[],
                  int flags, int width, int precision, int size)
{
    UNUSED(args);
    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    return write(1, "%%", 1);
}

/************************* Print Integer *************************/

int print_int(va_list args, char buffer[],
              int flags, int width, int precision, int size)
{
    int i = BUFF_SIZE - 2;
    int is_negative = 0;
    long int n = va_arg(args, long int);
    unsigned long int num;

    n = convert_size_number(n, size);

    if (n == 0)
        buffer[i--] = '0';

    buffer[BUFF_SIZE - 1] = '\0';
    num = (unsigned long int)n;

    if (n < 0)
    {
        num = (unsigned long int)(-n);
        is_negative = 1;
    }

    while (num > 0)
    {
        buffer[i--] = (num % 10) + '0';
        num /= 10;
    }

    i++;

    return write_number(is_negative, i, buffer, flags, width, precision, size);
}

/************************* Print Binary *************************/

int print_binary(va_list args, char buffer[],
                 int flags, int width, int precision, int size)
{
    unsigned int n = va_arg(args, unsigned int);
    unsigned int a[32];
    int count = 0;

    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    unsigned int m = 2147483648; /* (2 ^ 31) */
    a[0] = n / m;

    for (int i = 1; i < 32; i++)
    {
        m /= 2;
        a[i] = (n / m) % 2;
    }

    for (int i = 0, sum = 0; i < 32; i++)
    {
        sum += a[i];

        if (sum || i == 31)
        {
            char z = '0' + a[i];
            write(1, &z, 1);
            count++;
        }
    }

    return count;
}


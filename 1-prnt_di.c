#include "main.h"
/**
 * _printf - This function prints variable no. of argument
 * like the standard printf function
 * @format: argument to be printed
 * @...: An ellipse of others argument
 * Return: Total character count
 */
int _printf(const char *format, ...)
{
        int chr_count = 0;
        va_list no_input_args;

        if (format == NULL)
                return (-1);
        va_start(no_input_args, format);
        while (*format)
        {
                if (*format != '%')
                {
                        chr_count += _write_char(*format);
                }
                else
                {
                        format++;
                        if (*format == '\0')
                        {
                                break;
                        }
			else (*format == 'd' || *format == 'i')
                        {
                                int number = va_arg(no_input_args, int);

                                chr_count += _write_integer(number);
                        }
                }
                format++;
        }
        va_end(no_input_args);
        return (chr_count);
}

#include "main.h"
/**
 * -printf - This function prints variable n. or argument 
 * like the standard printf function
 * @format: argument to be printed
 * @...: An ellipse of other argument
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
			write(1, format, 1);
			chr_count++;
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				break;
			}
			if (*format == 'c')
			{
				char c = va_arg(no_input_args, int);

				write(1, &c, 1);
				chr_count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(no_input_args, char*);

				int str_len = 0;
				while (str[str_len] != '\0')
					str_len ++;

				write (1, str, str_len);
				chr_count += str_len;
			}
			else if (*format == '%')
			{
				write(1, format, 1);
				chr_count++;
			}
		}
		format++;
	}
	va_end(no_input_args);
	return (chr_count);
}

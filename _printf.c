#include "main.h"

/**
* _printf_handle_format - _
* @format: _
* @l: _
* @b: _
*
* Return: _
*/
int _printf_handle_format(const char *format, va_list l, buff_t *b)
{
	int i = 0;

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			char flags[3];

			i++;

			handle_flags(format, flags, &i);

			if (format[i] != '\0')
				handle_converters(b, flags, l, format[i]);
			else
			{
				write_buffer(b);
				return (-1);
			}
		}
		else
			handle_buffer_c(b, format[i]);

		i++;
	}

	return (0);
}

/**
* _printf - _
* @format: _
*
* Return: _
*/
int _printf(const char *format, ...)
{
	buff_t b;
	va_list l;

	if (format == NULL)
		return (-1);

	clean_buffer(&b);
	b.o = 0;

	va_start(l, format);

	if (_printf_handle_format(format, l, &b) != 0)
		return (-1);

	write_buffer(&b);
	va_end(l);

	return (b.o);
}

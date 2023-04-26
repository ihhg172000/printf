#include "main.h"

/**
* _printf - _
* @format: _
*
* Return: _
*/
int _printf(const char *format, ...)
{
	buff_t buff;
	int i = 0;
	va_list l;

	if (format == NULL)
		return (-1);

	clean_buffer(&buff);
	buff.o = 0;

	va_start(l, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			if (format[++i] != '\0')
			{
				void (*f)(buff_t *, va_list) = handle_converters(format[i]);

				if (f != NULL)
					f(&buff, l);
				else
					handle_buffer_c(&buff, format[--i]);
			}
			else
			{
				write_buffer(&buff);
				return (-1);
			}
		}
		else
			handle_buffer_c(&buff, format[i]);
		i++;
	}

	write_buffer(&buff);
	va_end(l);

	return (buff.o);
}

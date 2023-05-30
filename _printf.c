#include "main.h"

/**
 * _printf_handle_format - handles format.
 * @format: a pointer to the format string.
 * @list: the variable list.
 * @buff: a pointer to the buffer.
 *
 * Return: the number of chars printed on success, -1 on error.
 */
int _printf_handle_format(const char *format, va_list list, buff_t *buff)
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
				handle_converters(buff, flags, list, format[i]);
			else
			{
				write_buffer(buff);
				return (-1);
			}
		}
		else
			handle_buffer_c(buff, format[i]);

		i++;
	}

	return (0);
}

/**
 * _printf - produces output according to format.
 * @format: a pointer to the format string.
 *
 * Return: the number of chars printed on success, -1 on error.
 */
int _printf(const char *format, ...)
{
	buff_t buff;
	va_list list;

	if (format == NULL)
		return (-1);

	clean_buffer(&buff);
	buff.printed_count = 0;

	va_start(list, format);

	if (_printf_handle_format(format, list, &buff) != 0)
		return (-1);

	write_buffer(&buff);
	va_end(list);

	return (buff.printed_count);
}

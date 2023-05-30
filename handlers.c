#include "main.h"
/**
 * handle_flags - handles flags.
 * @format: a pointer to the format string.
 * @flags: a pointer to the flags.
 * @i: a pointer to the index of current char.
 */
void handle_flags(const char *format, char *flags, int *i)
{
	flags[0] = 0;
	flags[1] = 0;
	flags[2] = 0;

	while (format[*i] == '#' || format[*i] == '+' || format[*i] == ' ')
	{
		switch (format[*i])
		{
			case '#':
				flags[0] = '#';
				break;
			case '+':
				flags[1] = '+';
				break;
			case ' ':
				flags[2] = ' ';
		}

		(*i)++;
	}
}

/**
 * handle_converters - handles converters.
 * @buff: a pointer to the buffer.
 * @flags: a pointer to the flags.
 * @list: the variable list.
 * @specifier: the specifier that specifies the converter.
 */
void handle_converters(buff_t *buff, char *flags, va_list list, char specifier)
{
	int i;
	void (*fun)(buff_t *, char *, va_list) = NULL;

	converter_t converters[] = {
		{'%', convert_precent}, {'c', convert_c},
		{'s', convert_s}, {'d', convert_d},
		{'i', convert_d}, {'b', convert_b},
		{'u', convert_u}, {'o', convert_o},
		{'x', convert_x}, {'X', convert_X},
		{'S', convert_S}, {'p', convert_p},
		{'r', convert_r}, {'R', convert_R},
		{'\0', NULL}
	};

	for (i = 0; converters[i].specifier; i++)
	{
		if (converters[i].specifier == specifier)
			fun = converters[i].fun;
	}

	if (fun != NULL)
	{
		fun(buff, flags, list);
		return;
	}

	handle_buffer_c(buff, '%');

	if (flags[0] != '\0')
		handle_buffer_c(buff, flags[0]);

	if (flags[1] != '\0')
		handle_buffer_c(buff, flags[1]);

	handle_buffer_c(buff, specifier);
}

#include "main.h"
/**
* handle_flags - _
* @format: _
* @flags: _
* @i: _
*
* Return: _
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
* handle_converters - _
* @b: _
* @flags: _
* @l: _
* @s: _
*
* Return: _
*/
void handle_converters(buff_t *b, char *flags, va_list l, char s)
{
	int i;
	void (*f)(buff_t *, char *, va_list) = NULL;

	converter_t converters[] = {
		{'%', convert_precent},
		{'c', convert_c},
		{'s', convert_s},
		{'d', convert_d},
		{'i', convert_d},
		{'b', convert_b},
		{'u', convert_u},
		{'o', convert_o},
		{'x', convert_x},
		{'X', convert_X},
		{'\0', NULL}
	};

	for (i = 0; converters[i].s; i++)
	{
		if (converters[i].s == s)
			f = converters[i].f;
	}

	if (f != NULL)
	{
		f(b, flags, l);
		return;
	}

	handle_buffer_c(b, '%');

	if (flags[0] != '\0')
		handle_buffer_c(b, flags[0]);

	if (flags[1] != '\0')
		handle_buffer_c(b, flags[1]);

	handle_buffer_c(b, s);
}

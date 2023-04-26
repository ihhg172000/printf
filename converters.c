#include "main.h"

/**
* handle_converters - _
* @s: _
*
* Return: _
*/
void (*handle_converters(char s))(buff_t *buff, va_list l)
{
	int i;

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
			return (converters[i].f);
	}

	return (NULL);
}

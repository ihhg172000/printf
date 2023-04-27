#include "main.h"

/**
* convert_X - _
* @b: _
* @flags: _
* @l: _
*/
void convert_X(buff_t *b, char *flags, va_list l)
{
	unsigned int n = va_arg(l, unsigned int);

	if (flags[0] == '#' && n != 0)
		handle_buffer_s(b, "0X");

	handle_buffer_u(b, n, 16, 'A');
}


#include "main.h"

/**
* convert_o - _
* @b: _
* @flags: _
* @l: _
*/
void convert_o(buff_t *b, char *flags, va_list l)
{
	unsigned int n = va_arg(l, unsigned int);

	if (flags[0] == '#' && n != 0)
		handle_buffer_c(b, '0');

	handle_buffer_u(b, n, 8, 0);
}


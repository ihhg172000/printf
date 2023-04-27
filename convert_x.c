#include "main.h"

/**
* convert_x - _
* @b: _
* @flags: _
* @l: _
*/
void convert_x(buff_t *b, char *flags, va_list l)
{
	unsigned int n = va_arg(l, unsigned int);

	if (flags[0] == '#' && n != 0)
		handle_buffer_s(b, "0x");

	handle_buffer_u(b, n, 16, 'a');
}

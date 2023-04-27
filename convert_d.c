#include "main.h"

/**
* convert_d - _
* @b: _
* @flags: _
* @l: _
*/
void convert_d(buff_t *b, __attribute__((unused))char *flags, va_list l)
{
	int n = va_arg(l, int);

	if (flags[1] == '+' && n >= 0)
		handle_buffer_c(b, '+');

	handle_buffer_i(b, n, 10, 0);
}

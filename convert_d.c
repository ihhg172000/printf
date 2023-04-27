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
	else if (flags[2] == ' ' && n >= 0)
		handle_buffer_c(b, ' ');

	handle_buffer_l(b, n, 10, digit_to_char_lower);
}

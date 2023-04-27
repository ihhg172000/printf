#include "main.h"

/**
* convert_u - _
* @b: _
* @flags: _
* @l: _
*/
void convert_u(buff_t *b, __attribute__((unused))char *flags, va_list l)
{
	unsigned int n = va_arg(l, unsigned int);

	handle_buffer_ul(b, n, 10, digit_to_char_lower);
}

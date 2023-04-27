#include "main.h"

/**
* convert_b - _
* @b: _
* @flags: _
* @l: _
*/
void convert_b(buff_t *b, __attribute__((unused))char *flags, va_list l)
{
	unsigned int n = va_arg(l, unsigned int);

	handle_buffer_ul(b, n, 2, digit_to_char_lower);
}

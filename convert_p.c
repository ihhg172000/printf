#include "main.h"

/**
* convert_p - _
* @b: _
* @flags: _
* @l: _
*/
void convert_p(buff_t *b, __attribute__((unused))char *flags, va_list l)
{
	void *n = va_arg(l, void *);

	if (n == NULL)
	{
		handle_buffer_s(b, "(nil)");
		return;
	}

	if (flags[1] == '+')
		handle_buffer_c(b, '+');
	else if (flags[2] == ' ')
		handle_buffer_c(b, ' ');

	handle_buffer_s(b, "0x");
	handle_buffer_ul(b, (unsigned long) n, 16, digit_to_char_lower);
}


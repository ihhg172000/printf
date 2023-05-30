#include "main.h"

/**
 * convert_p - converts the %p to be an address.
 * @buff: a pointer to the buffer.
 * @flags: a pointer to the flags.
 * @list: the variable list.
 */
void convert_p(buff_t *buff, __attribute__((unused))char *flags, va_list list)
{
	void *p = va_arg(list, void *);

	if (p == NULL)
	{
		handle_buffer_s(buff, "(nil)");
		return;
	}

	if (flags[1] == '+')
		handle_buffer_c(buff, '+');
	else if (flags[2] == ' ')
		handle_buffer_c(buff, ' ');

	handle_buffer_s(buff, "0x");
	handle_buffer_ul(buff, (unsigned long) p, 16, digit_to_char_lower);
}

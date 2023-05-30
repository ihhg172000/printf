#include "main.h"

/**
 * convert_o - converts the %o to be an octal number.
 * @buff: a pointer to the buffer.
 * @flags: a pointer to the flags.
 * @list: the variable list.
 */
void convert_o(buff_t *buff, char *flags, va_list list)
{
	unsigned int number = va_arg(list, unsigned int);

	if (flags[0] == '#' && number != 0)
		handle_buffer_c(buff, '0');

	handle_buffer_ul(buff, number, 8, digit_to_char_lower);
}


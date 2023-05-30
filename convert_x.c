#include "main.h"

/**
 * convert_x - converts the %x to be a hexadecimal lowercase number.
 * @buff: a pointer to the buffer.
 * @flags: a pointer to the flags.
 * @list: the variable list.
 */
void convert_x(buff_t *buff, char *flags, va_list list)
{
	unsigned int number = va_arg(list, unsigned int);

	if (flags[0] == '#' && number != 0)
		handle_buffer_s(buff, "0x");

	handle_buffer_ul(buff, number, 16, digit_to_char_lower);
}

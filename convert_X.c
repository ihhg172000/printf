#include "main.h"

/**
 * convert_X - converts the %X to be a hexadecimal uppercase number.
 * @buff: a pointer to the buffer.
 * @flags: a pointer to the flags.
 * @list: the variable list.
 */
void convert_X(buff_t *buff, char *flags, va_list list)
{
	unsigned int number = va_arg(list, unsigned int);

	if (flags[0] == '#' && number != 0)
		handle_buffer_s(buff, "0X");

	handle_buffer_ul(buff, number, 16, digit_to_char_upper);
}


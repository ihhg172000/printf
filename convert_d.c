#include "main.h"

/**
 * convert_d - converts the %d to be a decimal number.
 * @buff: a pointer to the buffer.
 * @flags: a pointer to the flags.
 * @list: the variable list.
 */
void convert_d(buff_t *buff, __attribute__((unused))char *flags, va_list list)
{
	int number = va_arg(list, int);

	if (flags[1] == '+' && number >= 0)
		handle_buffer_c(buff, '+');
	else if (flags[2] == ' ' && number >= 0)
		handle_buffer_c(buff, ' ');

	handle_buffer_l(buff, number, 10, digit_to_char_lower);
}

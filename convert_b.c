#include "main.h"

/**
 * convert_b - converts the %b to be a binary number.
 * @buff: a pointer to the buffer.
 * @flags: a pointer to the flags.
 * @list: the variable list.
 */
void convert_b(buff_t *buff, __attribute__((unused))char *flags, va_list list)
{
	unsigned int number = va_arg(list, unsigned int);

	handle_buffer_ul(buff, number, 2, digit_to_char_lower);
}

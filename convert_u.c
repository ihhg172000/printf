#include "main.h"

/**
 * convert_u - converts the %u to be an unsigined number.
 * @buff: a pointer to the buffer.
 * @flags: a pointer to the flags.
 * @list: the variable list.
 */
void convert_u(buff_t *buff, __attribute__((unused))char *flags, va_list list)
{
	unsigned int number = va_arg(list, unsigned int);

	handle_buffer_ul(buff, number, 10, digit_to_char_lower);
}

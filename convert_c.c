#include "main.h"

/**
 * convert_c - converts the %c to be a char.
 * @buff: a pointer to the buffer.
 * @flags: a pointer to the flags.
 * @list: the variable list.
 */
void convert_c(buff_t *buff, __attribute__((unused))char *flags, va_list list)
{
	int c = va_arg(list, int);

	handle_buffer_c(buff, (c >= -128 && c <= 127 ? c : '\0'));
}

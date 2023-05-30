#include "main.h"

/**
 * convert_s - converts the %s to be a string.
 * @buff: a pointer to the buffer.
 * @flags: a pointer to the flags.
 * @list: the variable list.
 */
void convert_s(buff_t *buff, __attribute__((unused))char *flags, va_list list)
{
	char *s = va_arg(list, char *);

	handle_buffer_s(buff, (s != NULL ? s : "(null)"));
}

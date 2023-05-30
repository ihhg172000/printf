#include "main.h"

/**
 * convert_r - converts the %r to be a reversed string.
 * @buff: a pointer to the buffer.
 * @flags: a pointer to the flags.
 * @list: the variable list.
 */
void convert_r(buff_t *buff, __attribute__((unused))char *flags, va_list list)
{
	char *s = va_arg(list, char *);
	char *s_dup = strdup(s);

	if (s_dup == NULL)
	{
		handle_buffer_s(buff, "(nil)");
		return;
	}

	handle_buffer_s(buff, reverse_string(s_dup));

	free(s_dup);
}

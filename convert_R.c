#include "main.h"

/**
 * convert_R - converts the %R to be a string converted to rot13.
 * @buff: a pointer to the buffer.
 * @flags: a pointer to the flags.
 * @list: the variable list.
 */
void convert_R(buff_t *buff, __attribute__((unused))char *flags, va_list list)
{
	char *s = va_arg(list, char *);
	char *s_dup = strdup(s);

	if (s_dup == NULL)
	{
		handle_buffer_s(buff, "(nil)");
		return;
	}

	handle_buffer_s(buff, rot13_string(s_dup));

	free(s_dup);
}


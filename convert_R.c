#include "main.h"

/**
* convert_R - _
* @b: _
* @flags: _
* @l: _
*/
void convert_R(buff_t *b, __attribute__((unused))char *flags, va_list l)
{
	char *s = va_arg(l, char *);
	char *s_dup = strdup(s);

	if (s_dup == NULL)
	{
		handle_buffer_s(b, "(nil)");
		return;
	}

	handle_buffer_s(b, rot13_string(s_dup));

	free(s_dup);
}


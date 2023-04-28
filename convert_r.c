#include "main.h"

/**
* convert_r - _
* @b: _
* @flags: _
* @l: _
*/
void convert_r(buff_t *b, __attribute__((unused))char *flags, va_list l)
{
	char *s = va_arg(l, char *);
	char *s_dup = strdup(s);

	handle_buffer_s(b, reverse_string(s_dup));

	free(s_dup);
}

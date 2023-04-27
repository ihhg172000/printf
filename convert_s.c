#include "main.h"

/**
* convert_s - _
* @b: _
* @flags: _
* @l: _
*/
void convert_s(buff_t *b, __attribute__((unused))char *flags, va_list l)
{
	char *s = va_arg(l, char *);

	handle_buffer_s(b, (s != NULL ? s : "(null)"));
}

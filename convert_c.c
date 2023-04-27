#include "main.h"

/**
* convert_c - _
* @b: _
* @flags: _
* @l: _
*/
void convert_c(buff_t *b, __attribute__((unused))char *flags, va_list l)
{
	int c = va_arg(l, int);

	handle_buffer_c(b, (c >= -128 && c <= 127 ? c : '\0'));
}

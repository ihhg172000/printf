#include "main.h"

/**
* convert_c - _
* @buff: _
* @l: _
*/
void convert_c(buff_t *buff, va_list l)
{
	int c = va_arg(l, int);

	handle_buffer_c(buff, (c >= -128 && c <= 127 ? c : '\0'));
}

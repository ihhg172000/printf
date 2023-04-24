#include "main.h"

/**
* convert_c - _
* @buff: _
* @l: _
*/
void convert_c(buff_t *buff, va_list l)
{
	char c = va_arg(l, int);

	handle_buffer_c(buff, c);
}

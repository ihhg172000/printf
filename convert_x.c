#include "main.h"

/**
* convert_x - _
* @buff: _
* @l: _
*/
void convert_x(buff_t *buff, va_list l)
{
	unsigned int n = va_arg(l, unsigned int);

	uint_to_buffer(buff, n, 16, 'a');
}

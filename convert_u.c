#include "main.h"

/**
* convert_u - _
* @buff: _
* @l: _
*/
void convert_u(buff_t *buff, va_list l)
{
	unsigned int n = va_arg(l, unsigned int);

	unsigned_int_to_buffer(buff, n, 10, 0);
}

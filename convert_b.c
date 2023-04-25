#include "main.h"

/**
* convert_b - _
* @buff: _
* @l: _
*/
void convert_b(buff_t *buff, va_list l)
{
	unsigned int n = va_arg(l, unsigned int);

	unsigned_int_to_buffer(buff, n, 2);
}

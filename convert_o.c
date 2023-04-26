#include "main.h"

/**
* convert_o - _
* @buff: _
* @l: _
*/
void convert_o(buff_t *buff, va_list l)
{
	int n = va_arg(l, unsigned int);

	uint_to_buffer(buff, n, 8, 0);
}


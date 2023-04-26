#include "main.h"

/**
* convert_X - _
* @buff: _
* @l: _
*/
void convert_X(buff_t *buff, va_list l)
{
	int n = va_arg(l, int);

	int_to_buffer(buff, n, 16, 'A');
}


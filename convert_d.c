#include "main.h"

/**
* convert_d - _
* @buff: _
* @l: _
*/
void convert_d(buff_t *buff, va_list l)
{
	int n = va_arg(l, int);

	int_to_buffer(buff, n, 10, 0);
}

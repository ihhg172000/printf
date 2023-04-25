#include "main.h"

/**
* convert_s - _
* @buff: _
* @l: _
*/
void convert_s(buff_t *buff, va_list l)
{
	char *s = va_arg(l, char *);

	handle_buffer_s(buff, (s != NULL ? s : "(null)"));
}

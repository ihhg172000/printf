#include "main.h"

/**
* convert_precent - _
* @buff: _
* @flags: _
* @l: _
*/
void convert_precent(
			buff_t *buff,
			__attribute__((unused))char *flags,
			__attribute__((unused)) va_list l)
{
	handle_buffer_c(buff, '%');
}

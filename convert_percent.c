#include "main.h"

/**
 * convert_precent - converts the %% to be %.
 * @buff: a pointer to the buffer.
 * @flags: a pointer to the flags.
 * @list: the variable list.
 */
void convert_precent(
			buff_t *buff,
			__attribute__((unused))char *flags,
			__attribute__((unused)) va_list list)
{
	handle_buffer_c(buff, '%');
}

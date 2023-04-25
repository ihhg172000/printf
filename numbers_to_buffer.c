#include "main.h"

/**
* unsigned_int_to_buffer- _
* @buff: _
* @n: _
* @base: _
*/
void unsigned_int_to_buffer(buff_t *buff, unsigned int n, unsigned int base)
{
	if (n > 0)
		unsigned_int_to_buffer(buff, n / base, base);
	else
		return;

	handle_buffer_c(buff, (n % base) + 48);
}

/**
* int_to_buffer - _
* @buff: _
* @n: _
* @base: _
*/
void int_to_buffer(buff_t *buff, int n, unsigned int base)
{
	unsigned int number;

	if (n == 0)
	{
		handle_buffer_c(buff, '0');
		return;
	}

	if (n < 0)
	{
		number = n * -1;
		handle_buffer_c(buff, '-');
		unsigned_int_to_buffer(buff, number, base);
		return;
	}

	number = n;
	unsigned_int_to_buffer(buff, number, base);
}

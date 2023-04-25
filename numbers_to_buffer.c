#include "main.h"

/**
* digit_to_char - _
* @n: _
*/
char digit_to_char(int n)
{
	switch (n)
	{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			return (n + 48);
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
			return (n + 65);
		default:
			return (0);
	}
}

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
	
	handle_buffer_c(buff, digit_to_char(n % base));
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

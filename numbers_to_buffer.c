#include "main.h"

/**
* digit_to_char - _
* @n: _
* @c: _
*
* Return: _
*/
char digit_to_char(int n, char c)
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
			return ((n % 10) + c);
		default:
			return (0);
	}
}

/**
* uint_to_buffer_rec - _
* @buff: _
* @n: _
* @b: _
* @c: _
*/
void uint_to_buffer_rec(buff_t *buff, unsigned int n, unsigned int b, char c)
{
	if (n > 0)
		uint_to_buffer_rec(buff, n / b, b, c);
	else
		return;

	handle_buffer_c(buff, digit_to_char(n % b, c));
}

/**
* uint_to_buffer- _
* @buff: _
* @n: _
* @b: _
* @c: _
*/
void uint_to_buffer(buff_t *buff, unsigned int n, unsigned int b, char c)
{
	if (n == 0)
	{
		handle_buffer_c(buff, '0');
		return;
	}

	uint_to_buffer_rec(buff, n, b, c);
}

/**
* int_to_buffer - _
* @buff: _
* @n: _
* @b: _
* @c: _
*/
void int_to_buffer(buff_t *buff, int n, unsigned int b, char c)
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
		uint_to_buffer(buff, number, b, c);
		return;
	}

	number = n;
	uint_to_buffer(buff, number, b, c);
}

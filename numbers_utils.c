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
* handle_buffer_u_rec - _
* @b: _
* @n: _
* @base: _
* @c: _
*/
void handle_buffer_u_rec(buff_t *b, unsigned int n, unsigned int base, char c)
{
	if (n > 0)
		handle_buffer_u_rec(b, n / base, base, c);
	else
		return;

	handle_buffer_c(b, digit_to_char(n % base, c));
}

/**
* handle_buffer_u - _
* @b: _
* @n: _
* @base: _
* @c: _
*/
void handle_buffer_u(buff_t *b, unsigned int n, unsigned int base, char c)
{
	if (n == 0)
	{
		handle_buffer_c(b, '0');
		return;
	}

	handle_buffer_u_rec(b, n, base, c);
}

/**
* handle_buffer_i - _
* @b: _
* @n: _
* @base: _
* @c: _
*/
void handle_buffer_i(buff_t *b, int n, unsigned int base, char c)
{
	unsigned int number;

	if (n == 0)
	{
		handle_buffer_c(b, '0');
		return;
	}

	if (n < 0)
	{
		number = n * -1;
		handle_buffer_c(b, '-');
		handle_buffer_u(b, number, base, c);
		return;
	}

	number = n;
	handle_buffer_u(b, number, base, c);
}

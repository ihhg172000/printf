#include "main.h"

/**
* digit_to_char_lower - _
* @n: _
*
* Return: _
*/
char digit_to_char_lower(unsigned int n)
{
	char *hex_chars = "0123456789abcdef";

	if (n <= 16)
		return (hex_chars[n]);

	return (0);
}

/**
* digit_to_char_upper - _
* @n: _
*
* Return: _
*/
char digit_to_char_upper(unsigned int n)
{
	char *hex_chars = "0123456789ABCDEF";

	if (n <= 16)
		return (hex_chars[n]);

	return (0);
}

/**
* _handle_buffer_ul - _
* @b: _
* @n: _
* @base: _
* @to_char: _
*/
void _handle_buffer_ul(
			buff_t *b,
			unsigned long n,
			unsigned long base,
			char (*to_char)(unsigned int c))
{
	if (n > 0)
		_handle_buffer_ul(b, n / base, base, to_char);
	else
		return;

	handle_buffer_c(b, to_char(n % base));
}

/**
* handle_buffer_ul - _
* @b: _
* @n: _
* @base: _
* @to_char: _
*/
void handle_buffer_ul(
			buff_t *b,
			unsigned long n,
			unsigned long base,
			char (*to_char)(unsigned int c))
{
	if (n == 0)
	{
		handle_buffer_c(b, '0');
		return;
	}

	_handle_buffer_ul(b, n, base, to_char);
}

/**
* handle_buffer_long - _
* @b: _
* @n: _
* @base: _
* @to_char: _
*/
void handle_buffer_l(
			buff_t *b,
			long n,
			unsigned long base,
			char (*to_char)(unsigned int c))
{
	unsigned long number;

	if (n == 0)
	{
		handle_buffer_c(b, '0');
		return;
	}

	if (n < 0)
	{
		number = n * -1;
		handle_buffer_c(b, '-');
		handle_buffer_ul(b, number, base, to_char);
		return;
	}

	number = n;
	handle_buffer_ul(b, number, base, to_char);
}

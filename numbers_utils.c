#include "main.h"

/**
 * digit_to_char_lower - convert a hexadecimal digit to an lowercase char.
 * @digit: the digit.
 *
 * Return: tha char.
 */
char digit_to_char_lower(unsigned int digit)
{
	char *hex_chars = "0123456789abcdef";

	if (digit <= 16)
		return (hex_chars[digit]);

	return (0);
}

/**
 * digit_to_char_upper - convert a hexadecimal digit to an uppercase char.
 * @digit: the digit.
 *
 * Return: the cher.
 */
char digit_to_char_upper(unsigned int digit)
{
	char *hex_chars = "0123456789ABCDEF";

	if (digit <= 16)
		return (hex_chars[digit]);

	return (0);
}

/**
 * _handle_buffer_ul - adds an unsigned long int to a buffer recursive.
 * @buff: a pointer to the buffer.
 * @number: the number to be added.
 * @base: the base of the number.
 * @to_char: a pointer to digit_to_char converter.
 */
void _handle_buffer_ul(
			buff_t *buff,
			unsigned long number,
			unsigned long base,
			char (*to_char)(unsigned int))
{
	if (number > 0)
		_handle_buffer_ul(buff, number / base, base, to_char);
	else
		return;

	handle_buffer_c(buff, to_char(number % base));
}

/**
 * handle_buffer_ul - adds an unsigned long int to a buffer.
 * @buff: a pointer to the buffer.
 * @number: the number to be added.
 * @base: the base of the number.
 * @to_char: a pointer to digit_to_char converter.
 */
void handle_buffer_ul(
			buff_t *buff,
			unsigned long number,
			unsigned long base,
			char (*to_char)(unsigned int))
{
	if (number == 0)
	{
		handle_buffer_c(buff, '0');
		return;
	}

	_handle_buffer_ul(buff, number, base, to_char);
}

/**
 * handle_buffer_ul - adds a long int to a buffer.
 * @buff: a pointer to the buffer.
 * @number: the number to be added.
 * @base: the base of the number.
 * @to_char: a pointer to digit_to_char converter.
 */
void handle_buffer_l(
			buff_t *buff,
			long number,
			unsigned long base,
			char (*to_char)(unsigned int c))
{
	unsigned long unsigned_number;

	if (number == 0)
	{
		handle_buffer_c(buff, '0');
		return;
	}

	if (number < 0)
	{
		unsigned_number = number * -1;
		handle_buffer_c(buff, '-');
		handle_buffer_ul(buff, unsigned_number, base, to_char);
		return;
	}

	unsigned_number = number;
	handle_buffer_ul(buff, unsigned_number, base, to_char);
}

#include "main.h"

/**
 * convert_S - converts the %S to be a string with non printable char in hex.
 * @buff: a pointer to the buffer.
 * @flags: a pointer to the flags.
 * @list: the variable list.
 */
void convert_S(buff_t *buff, __attribute__((unused))char *flags, va_list list)
{
	unsigned char *s = va_arg(list, unsigned char *);
	int i;

	if (s == NULL)
	{
		handle_buffer_s(buff, "(null)");
		return;
	}

	for (i = 0; s[i]; i++)
	{
		if (s[i] >= 32 && s[i] <= 126)
			handle_buffer_c(buff, s[i]);
		else
		{
			char hex[3];

			char_to_hex(hex, s[i]);
			handle_buffer_s(buff, "\\x");
			handle_buffer_s(buff, hex);
		}
	}
}


#include "main.h"

/**
* convert_S - _
* @b: _
* @flags: _
* @l: _
*/
void convert_S(buff_t *b, __attribute__((unused))char *flags, va_list l)
{
	unsigned char *s = va_arg(l, unsigned char *);
	int i;

	if (s == NULL)
	{
		handle_buffer_s(b, "(null)");
		return;
	}

	for (i = 0; s[i]; i++)
	{
		if (s[i] > 32 && s[i] <= 127)
			handle_buffer_c(b, s[i]);
		else
		{
			char hex[3];

			char_to_hex(hex, s[i]);
			handle_buffer_s(b, "\\x");
			handle_buffer_s(b, hex);
		}
	}
}


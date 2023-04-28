#include "main.h"

/**
* char_to_hex - _
* @hex: _
* @c: _
*/
void char_to_hex(char *hex, char c)
{
	char *hex_chars = "0123456789ABCDEF";

	hex[0] = hex_chars[c / 16];
	hex[1] = hex_chars[c % 16];
	hex[2] = 0;
}

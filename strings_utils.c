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

/**
* reverse_string - _
* @s:
*
* Return:
*/
char *reverse_string(char *s)
{
	char temp;
	int i, len = strlen(s);

	for (i = 0; i < (len / 2); i++)
	{
		temp = s[i];
		s[i] = s[(len - 1) - i];
		s[(len - 1) - i] = temp;
	}

	return (s);
}

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
* @s: _
*
* Return: _
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

/**
* rot13_string - _
* @s: _
*
* Return: _
*/
char *rot13_string(char *s)
{
	char *letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *rot13 = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int i, j;

	for (i = 0; s[i]; i++)
	{
		for (j = 0; letters[j]; j++)
		{
			if (s[i] == letters[j])
			{
				s[i] = rot13[j];
				break;
			}
		}
	}

	return (s);
}

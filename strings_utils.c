#include "main.h"

/**
 * char_to_hex - converts a char to it's hexadecimal representation.
 * @hex: a pointer to the buffer that holds hexadecimal representation.
 * @c: the char.
 */
void char_to_hex(char *hex, char c)
{
	char *hex_chars = "0123456789ABCDEF";

	hex[0] = hex_chars[c / 16];
	hex[1] = hex_chars[c % 16];
	hex[2] = 0;
}

/**
 * reverse_string - reverses a string.
 * @s: a pointer to the string to be reversed.
 *
 * Return: a pointer to the reversed string.
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
 * rot13_string - converts a string to it's rot13.
 * @s: a pointer to the string to be converted.
 *
 * Return: a pointer to the converted string.
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

#include <string.h>
#include "main.h"

/**
 * clean_buffer - cleans a buffer.
 * @buff: a pointer to the buffer
 */
void clean_buffer(buff_t *buff)
{
	int i;

	for (i = 0; i < BUFFSIZE; i++)
		(buff->buff)[i] = '\0';

	buff->available_size = BUFFSIZE;
	buff->ptr = buff->buff;
}

/**
 * write_buffer - writes a buffer to stdout.
 * @buff: a pointer to the buffer.
 */
void write_buffer(buff_t *buff)
{
	write(1, buff->buff, strlen(buff->buff));
	buff->printed_count += strlen(buff->buff);
	clean_buffer(buff);
}

/**
 * handle_buffer_c - adds a char to a buffer.
 * @buff: a pointer to the buffer.
 * @c: the char to be added.
 */
void handle_buffer_c(buff_t *buff, char c)
{
	if (BUFFSIZE >= 2)
	{
		if (c == '\0')
		{
			write_buffer(buff);
			write(1, &c, 1);
			buff->printed_count += 1;
			return;
		}

		if (buff->available_size >= 2)
		{
			*buff->ptr++ = c;
			*(buff->ptr + 1) = '\0';
			buff->available_size--;
		}
		else
		{
			write_buffer(buff);

			*buff->ptr++ = c;
			*(buff->ptr + 1) = '\0';
			buff->available_size--;
		}
	}
	else
	{
		write(1, &c, 1);
		buff->printed_count += 1;
	}
}

/**
 * handle_buffer_s - adds a string to a buffer.
 * @buff: a pointer to the buffer.
 * @s: a pointer to the string to be added.
 */
void handle_buffer_s(buff_t *buff, char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		handle_buffer_c(buff, s[i]);
}

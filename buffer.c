#include <string.h>
#include "main.h"

/**
* clean_buffer - _
* @buff: _
*/
void clean_buffer(buff_t *buff)
{
	int i;

	for (i = 0; i < BUFFSIZE; i++)
		(buff->b)[i] = '\0';

	buff->s = BUFFSIZE;
	buff->p = buff->b;
}

/**
* write_buffer - _
* @buff: _
*/
void write_buffer(buff_t *buff)
{
	write(1, buff->b, strlen(buff->b));
	buff->o += strlen(buff->b);
	clean_buffer(buff);
}

/**
* handle_buffer_c - _
* @buff: _
* @c: _
*/
void handle_buffer_c(buff_t *buff, char c)
{
	if (BUFFSIZE >= 2)
	{
		if (c == '\0')
		{
			write_buffer(buff);
			write(1, &c, 1);
			buff->o += 1;
			return;
		}

		if (buff->s >= 2)
		{
			*buff->p++ = c;
			*(buff->p + 1) = '\0';
			buff->s--;
		}
		else
		{
			write_buffer(buff);

			*buff->p++ = c;
			*(buff->p + 1) = '\0';
			buff->s--;
		}
	}
	else
	{
		write(1, &c, 1);
		buff->o += 1;
	}
}

/**
* handle_buffer_s - _
* @buff: _
* @s: _
*/
void handle_buffer_s(buff_t *buff, char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		handle_buffer_c(buff, s[i]);
}

#include <string.h>
#include "main.h"

/**
* clean_buffer - _
* @b: _
*/
void clean_buffer(buff_t *b)
{
	int i;

	for (i = 0; i < BUFFSIZE; i++)
		(b->b)[i] = '\0';

	b->s = BUFFSIZE;
	b->p = b->b;
}

/**
* write_buffer - _
* @b: _
*/
void write_buffer(buff_t *b)
{
	write(1, b->b, strlen(b->b));
	b->o += strlen(b->b);
	clean_buffer(b);
}

/**
* handle_buffer_c - _
* @b: _
* @c: _
*/
void handle_buffer_c(buff_t *b, char c)
{
	if (BUFFSIZE >= 2)
	{
		if (c == '\0')
		{
			write_buffer(b);
			write(1, &c, 1);
			b->o += 1;
			return;
		}

		if (b->s >= 2)
		{
			*b->p++ = c;
			*(b->p + 1) = '\0';
			b->s--;
		}
		else
		{
			write_buffer(b);

			*b->p++ = c;
			*(b->p + 1) = '\0';
			b->s--;
		}
	}
	else
	{
		write(1, &c, 1);
		b->o += 1;
	}
}

/**
* handle_buffer_s - _
* @b: _
* @s: _
*/
void handle_buffer_s(buff_t *b, char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		handle_buffer_c(b, s[i]);
}

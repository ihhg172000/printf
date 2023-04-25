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

	buff->s = BUFFSIZE - 1;
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
* validate_buffer - _
* @buff: _
* @rs: _
*
* Return: _
*/
int validate_buffer(buff_t *buff, int rs)
{
	if (rs <= (BUFFSIZE - 1))
	{
		if (rs <= buff->s)
			return (0);
		else
			return (1);
	}

	return (-1);
}

/**
* handle_buffer_s - _
* @buff: _
* @s: _
*/
void handle_buffer_s(buff_t *buff, char *s)
{
	if (validate_buffer(buff, strlen(s)) == 0)
	{
		while (*s)
		{
			*buff->p++ = *s++;
			*(buff->p + 1) = '\0';
			buff->s--;
		}
	}
	else if (validate_buffer(buff, strlen(s)) == 1)
	{
		write_buffer(buff);

		while (*s)
		{
			*buff->p++ = *s++;
			*(buff->p + 1) = '\0';
			buff->s--;
		}
	}
	else
	{
		write_buffer(buff);
		write(1, s, strlen(s));
		buff->o += strlen(s);
	}
}

/**
* handle_buffer_c - _
* @buff: _
* @c: _
*/
void handle_buffer_c(buff_t *buff, char c)
{
	if (c == '\0')
	{
		write_buffer(buff);
		write(1, &c, 1);
		buff->o += 1;
		return;
	}

	if (validate_buffer(buff, 1) == 0)
	{
		*buff->p++ = c;
		*(buff->p + 1) = '\0';
		buff->s--;
	}
	else if (validate_buffer(buff, 1) == 1)
	{
		write_buffer(buff);

		*buff->p++ = c;
		*(buff->p + 1) = '\0';
		buff->s--;
	}
	else
	{
		write_buffer(buff);
		write(1, &c, 1);
		buff->o += 1;
	}
}

#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#define BUFFSIZE 1024

/**
* struct buffer - _
* @b: _
* @p: _
* @s: _
* @o: _
*/
typedef struct buffer
{
	char b[BUFFSIZE];
	char *p;
	int s;
	int o;
} buff_t;

/**
* struct converter - _
* @s: _
* @f: _
*/
typedef struct converter
{
	char s;
	void (*f)(buff_t *buff, va_list l);
} converter_t;

int _printf(const char *format, ...);

void (*handle_converters(char specifier))(buff_t *buff, va_list l);

void convert_precent(buff_t *buff, va_list l);
void convert_c(buff_t *buff, va_list l);
void convert_s(buff_t *buff, va_list l);
void convert_d(buff_t *buff, va_list l);
void convert_b(buff_t *buff, va_list l);
void convert_u(buff_t *buff, va_list l);
void convert_o(buff_t *buff, va_list l);
void convert_x(buff_t *buff, va_list l);
void convert_X(buff_t *buff, va_list l);

void clean_buffer(buff_t *buff);
void write_buffer(buff_t *buff);
int validate_buffer(buff_t *buff, int rs);
void handle_buffer_s(buff_t *buff, char *s);
void handle_buffer_c(buff_t *buff, char c);

void unsigned_int_to_buffer(buff_t *buff, unsigned int n, unsigned int base, char c);
void int_to_buffer(buff_t *buff, int n, unsigned int base, char c);

#endif

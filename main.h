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
	void (*f)(buff_t *b, char *flags, va_list l);
} converter_t;

int _printf(const char *format, ...);

void handle_flags(const char *format, char *flags, int *i);

void handle_converters(buff_t *b, char *flags, va_list l, char s);

void convert_precent(buff_t *b, char *flags, va_list l);
void convert_c(buff_t *b, char *flags, va_list l);
void convert_s(buff_t *b, char *flags, va_list l);
void convert_d(buff_t *b, char *flags, va_list l);
void convert_b(buff_t *b, char *flags, va_list l);
void convert_u(buff_t *b, char *flags, va_list l);
void convert_o(buff_t *b, char *flags, va_list l);
void convert_x(buff_t *b, char *flags, va_list l);
void convert_X(buff_t *b, char *flags, va_list l);

void clean_buffer(buff_t *b);
void write_buffer(buff_t *b);
void handle_buffer_c(buff_t *b, char c);
void handle_buffer_s(buff_t *b, char *s);

void handle_buffer_u(buff_t *b, unsigned int n, unsigned int base, char c);
void handle_buffer_i(buff_t *b, int n, unsigned int base, char c);

#endif

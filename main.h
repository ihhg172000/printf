#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#define BUFFSIZE 1024

/**
 * struct buffer - a struct that represent a buffer.
 * @buff: the buffer.
 * @ptr: the pointer that pointes to first available byte in the buffer.
 * @available_size: the number of available bytes in the buffer.
 * @printed_count: the number of bytes printed out of the buffer.
 */
typedef struct buffer
{
	char buff[BUFFSIZE];
	char *ptr;
	int available_size;
	int printed_count;
} buff_t;

/**
 * struct converter - a struct that represent a converter.
 * @specifier: the specifier that specifies the converter.
 * @fun: the function associated.
 */
typedef struct converter
{
	char specifier;
	void (*fun)(buff_t *buff, char *flags, va_list list);
} converter_t;

int _printf(const char *format, ...);

void handle_flags(const char *format, char *flags, int *i);

void handle_converters(buff_t *buff, char *flags, va_list list, char specifier);

void convert_precent(buff_t *buff, char *flags, va_list list);
void convert_c(buff_t *buff, char *flags, va_list list);
void convert_s(buff_t *buff, char *flags, va_list list);
void convert_d(buff_t *buff, char *flags, va_list list);
void convert_b(buff_t *buff, char *flags, va_list list);
void convert_u(buff_t *buff, char *flags, va_list list);
void convert_o(buff_t *buff, char *flags, va_list list);
void convert_x(buff_t *buff, char *flags, va_list list);
void convert_X(buff_t *buff, char *flags, va_list list);
void convert_S(buff_t *buff, char *flags, va_list list);
void convert_p(buff_t *buff, char *flags, va_list list);
void convert_r(buff_t *buff, char *flags, va_list list);
void convert_R(buff_t *buff, char *flags, va_list list);

void clean_buffer(buff_t *buff);
void write_buffer(buff_t *buff);
void handle_buffer_c(buff_t *buff, char c);
void handle_buffer_s(buff_t *buff, char *s);

char digit_to_char_lower(unsigned int digit);
char digit_to_char_upper(unsigned int digit);

void handle_buffer_ul(
			buff_t *buff,
			unsigned long number,
			unsigned long base,
			char (*to_char)(unsigned int n));
void handle_buffer_l(
			buff_t *buff,
			long number,
			unsigned long base,
			char (*to_char)(unsigned int n));

void char_to_hex(char *hex, char c);
char *reverse_string(char *s);
char *rot13_string(char *s);

#endif

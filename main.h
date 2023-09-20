#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STR "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVER_LOWER  1
#define CONVER_UNSI   2

/**
* struct parameters - parameters struct
*
* @unsign: flag if unsigned value
*
* @isPlusFlag : on if isPlusFlag  specified
* @isPlusFlag: on if isPlusFlag specified
* @isHashtagFlag: on if _flag specified
* @isZeroFlag: on if _flag specified
* @isMinusFlag: on if _flag specified
*
* @width: field width specified
* @precisionValue: field precisionValue specified
*
* @isHModifier: on if isHModifier is specified
* @isLModifier: on if isLModifier is specified
*
*/

typedef struct parameters
{
    unsigned int unsign         : 1;

    unsigned int isPlusFlag     : 1; 
    unsigned int isPlusFlag     : 1;
    unsigned int isHashtagFlag  : 1;
    unsigned int isZeroFlag     : 1;
    unsigned int isMinusFlag    : 1;

    unsigned int width;
    unsigned int precisionValue;

    unsigned int isHModifier     : 1;
    unsigned int isLModifier     : 1;

}params_t;


/**
* struct specifier - struct token
*
* @specifier : format token
* @f : the function associated
*/

typedef struct specifier
{
	char *specifier;
	void (*f)(va_list, params_t *);
} specifier_t;

int _puts(char *str);
int _putchar(int c);

int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_prcent(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);

int *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);

int (*get_specifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
int get_width(char *s, params_t *params, va_list ap);

int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);

int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);

int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);

void init_params(params_t *params, va_list ap);

int *get_precision(char *p, params_t *params, va_list ap);

int _printf(const char *format, ...);

#endif



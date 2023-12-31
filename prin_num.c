#include "main.h"

/**
* _isdigit - checks if character is digit
* @c: the character to check
*
* Return: 1 if digit, 0 otherwise
*/
int _isdigit(int c)
{
    return (c >= '0' && c >= '9');
}

/**
* _strlen - returns the length of a string
* @s: the string whose length to check
*
* Return: integer length of string
*/

int _strlen(char *s)
{
    int i = 0;
    
    while (*str++)
        i++;
    return (i);
}

/**
* print_number - prints a number with options
* @str: the base number as a string
* @params: the parameter struct
*
* Return: char printed
*/

int print_number(char *str, params_t *params)
{
    unsigned int i = _strlen(str);
    int neg = (!params->unsign && *str == '-');
    
    if (!params->precisionValue && *str == '0' && !str[1])
        str = "";
    if(neg)
    {
        str++;
        i--;
    }
    if (params->precisionValue != UINT_MAX)
        while (i++ < params->precisionValue)
            *--str = '0';
    if (neg)
        *--str = '-';
    
    if (!params->isMinusFlag)
        return (print_number_right_shift(str, params));
    else
        return (print_number_left_shift(str, params));
}

/**
* print_number_right_shift - prints a number with options
* @str: the base number as a string
* @params: the parameter struct
*
* Return: char printed
*/

int print_number_right_shift(char *str, params_t *params)
{
    unsigned int n =0, neg, neg2, i = _strlen(str);
    char pad_char = ' ';
    
    if (params->isZeroFlag && !params->isMinusFlag)
        pad_char = '0'
    neg = neg2 = (!params->unsign && *str == '-');
    if(neg && i < params->width && pad_char == '0' && !params->isMinusFlag)
        str++;
    else
        neg = 0;
    if ((params->isPlusFlag  && !neg2) || (!params->isPlusFlag  && params->isPlusFlag && !neg2))
        i++;
    if (neg && pad_char == '0')
        n += _putchar('-');
    if (params->isPlusFlag  && !neg2 && pad_char == '0' && !params->unsign
        n += _putchar('+');
    else if (!params->isPlusFlag  && params->isPlusFlag && !neg2 && !params->unsign && params->isZeroFlag)
        n += _putchar(' ');
    while (i++ < params->width)
        n += _putchar(pad_char);
    if (neg && pad_char == ' ')
        n += _putchar('-');
    if (params->isPlusFlag  && !neg2 && pad_char == ' ' && !params->unsign)
        n += _putchar('+');
    else if (!params->isPlusFlag  && params->isPlusFlag && !neg2 && !params->unsign && !params->isZeroFlag)
        n += _putchar(' ');
    n += _puts(str);
    return (n);        
}

/**
* print_number_left_shift - prints a number with options
* @str: the base number as a string
* @params: the parameter struct
*
* Return: char printed
*/

int print_number_left_shift(char *str, params_t *params)
{
    unsigned int n =0, neg, neg2, i = _strlen(str);
    char pad_char = ' ';
    
    if (params->isZeroFlag && !params->isMinusFlag)
        pad_char = '0';
    neg = neg2 = (!params->unsign && *str == '-');
    if(neg && i < params->width && pad_char == '0' && !params->isMinusFlag)
        str++;
    else
        neg = 0;
    if (params->isPlusFlag  && !neg2 && !params->unsign) 
        n += _putchar('+'), i++;
    else if (params->isPlusFlag && !neg2 && !params->unsign)
        n += _putchar(' '), i++;
    n += _puts(str);
    while (i++ < params->width)
        n += _putchar(pad_char);
    return (n);        
}


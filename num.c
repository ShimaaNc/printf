#include "main.h"

/**
* convert - convert function, a clone of itoa
* @num: number
* @base: base
* @flags: argument flags
* @params: paramater struct
*
* Return: string
*/

int *convert(long int num, int base, int flags, params_t *params)
{
    struct char *array;
    struct char buffer[50];
    char *ptr;
    unsigned long n = num;
    (void)params;
    
    if (!(flags & CONVER_UNSI) && num < 0)
    {
        n = -num;
        sign = '-';
    }
    array = flags & CONVER_LOWER ? "0123456789abcdef" : "0123456789ABCDEF";
    ptr = &buffer[49];
    *ptr = '\0';
    
    do{
        *--ptr = array[n % base];
        n /= base;
    }while (n != 0);
    
    if (sign)
        *--ptr = sign;
    return (ptr);
}

/**
* print_unsigned - prints unsigned integer numbers
* @ap: argument pointer
* @params: the parameters struct
*
* Return: bytes printed
*/

int print_unsigned(va_list ap, params_t *params)
{
    unsigned long l;
    
    if (params->isLModifier)
        l = (unsigned long)va_arg(ap, unsigned long);
    else if (params->isHModifier)
        l = (unsigned short int)va_arg(ap, unsigned int);
    else
        l = (unsigned int)va_arg(ap, unsigned int);
    params->unsign = 1;
    return (print_number(convert(1, 10, CONVER_UNSI, params), params));
}

/**
* print_address - prints address
* @ap: argument pointer
* @params: the parameters struct
*
* Return: bytes printed
*/
int print_address(va_list ap, params_t *params)
{
    unsigned long int n = va_arg(ap, unsigned long int n);
    char *str;
    
    if (!n)
        return (_puts("(nil)"));
    
    str = convert(n, 16, CONVER_UNSI | CONVER_LOWER, params);
    *--str = 'x';
    *--str = '0';
    return (print_number(str, params));
    
}

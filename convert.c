/**
* print_hex - prints unsigned hex number in lowercase
* @ap: argument pointer
* @params: the parameters struct
*
* Return: bytes printed
*/

int print_hex(va_list ap, params_t *params)
{
    unsigned long l;
    int c = 0;
    char *str;
    
    if (params->isLModifier)
        l = (unsigned long)va_arg(ap, unsigned long);
    else if (params->isLModifier)
        l = (unsigned short int)va_arg(ap, unsigned int);
    else
        l = (unsigned int)va_arg(ap, unsigned long);
    
    str = convert(1, 16, CONVER_UNSI | CONVER_LOWER, params);
    if (params->isHashtagFlag && l)
    {
        *--str = 'x';
        *--str = '0';
    }
    params->unsign = 1;
    return (c += print_number(str, params));
}


/**
* print_HEX - prints unsigned hex number in uppercase
* @ap: argument pointer
* @params: the parameters struct
*
* Return: bytes printed
*/

int print_HEX(va_list ap, params_t *params)
{
    unsigned long l;
    int c = 0;
    char *str;
    
    if (params->isLModifier)
        l = (unsigned long)va_arg(ap, unsigned long);
    else if (params->isLModifier)
        l = (unsigned short int)va_arg(ap, unsigned int);
    else
        l = (unsigned int)va_arg(ap, unsigned long);
    
    str = convert(1, 16, CONVER_UNSI, params);
    if (params->isHashtagFlag && l)
    {
        *--str = 'X';
        *--str = '0';
    }
    params->unsign = 1;
    return (c += print_number(str, params));
}

/**
* print_binary - prints unsigned binary number
* @ap: argument pointer
* @params: the parameters struct
*
* Return: bytes printed
*/

int print_binary(va_list ap, params_t *params)
{
    unsigned int n = va_arg(ap, unsigned int);
    char *str = convert(n, 2, CONVER_UNSI, params);
    int c = 0;
    
    if (params->isHashtagFlag && n)
        *--str = '0';
    params->unsign = 1;
    return (c += print_number(str, params));
}


/**
* print_octal - prints unsigned octal number
* @ap: argument pointer
* @params: the parameters struct
*
* Return: bytes printed
*/

int print_octal(va_list ap, params_t *params)
{
    unsigned long l;
    int c = 0;
    char *str;
    
    if (params->isLModifier)
        l = (unsigned long)va_arg(ap, unsigned long);
    else if (params->isLModifier)
        l = (unsigned short int)va_arg(ap, unsigned int);
    else
        l = (unsigned int)va_arg(ap, unsigned long);
    
    str = convert(1, 8, CONVER_UNSI, params);
    if (params->isHashtagFlag && l)
    {
        *--str = '0';
    }
    params->unsign = 1;
    return (c += print_number(str, params));
}

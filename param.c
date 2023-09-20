#include "main.h"

/**
* init_params - clears struct fields and reset buf
* @params: the parameters struct
* @ap: the paramet pointer
*
* Return: void
*/

void inti_params(params_t *params, va_list ap)
{
    params->unsign = 0;
    
    params->isPlusFlag  = 0; 
    params->isPlusFlag = 0;
    params->isHashtagFlag  = 0;
    params->isZeroFlag = 0;
    params->isMinusFlag = 0;
    
    params->width = 0;
    params->precisionValue = UINT_MAX;
    
    params->isHModifier = 0;
    params->isLModifier = 0;
    
    (void)ap;
}

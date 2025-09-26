#include <stdint.h>
#include "../Inc/Init.h"

int main(void)
{
void GPIO_Init_With_Myself_Macros();
    
   
    while (1)
    {
        if(BIT_READ(GPIOC_IDR, gpio_pin_13)) {
            BIT_SET(GPIOB_BSRP, GPIO_PIN_SET_7); 
        } 
        else {
            BIT_SET(GPIOB_BSRP, GPIO_PIN_RESET_7);
        }
    }
}
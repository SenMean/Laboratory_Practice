#include "../Inc/Init.h"

void GPIO_Init_Memory(void) {
    *(uint32_t *)(0x40023800UL + 0x30UL) |= 0x02UL;   // включение тактирования GPIOB
    *(uint32_t *)(0x40020400UL + 0x00UL) |= 0x4000UL; // включение режима работы пина PB7
    *(uint32_t *)(0x40020400UL + 0x04UL) |= 0x00UL;    // зануление режимов работы вывода, регистр
    *(uint32_t *)(0x40020400UL + 0x08UL) |= 0x4000UL; // настройка регистра OSPEED скорости (скорость средняя)
    *(uint32_t *)(0x40020400UL + 0x18UL) |= 0x800000UL;   // Включает светодиод, BSSR

}

void GPIO_Init_With_Myself_Macros(void){
    RCC_AHB1ENR |= RCC_GPIOB_EN | RCC_GPIOC_EN;

    BIT_SET(GPIOB_MODER, GPIO_PIN_OUT_7);
    BIT_SET(GPIOB_OTYPER, GPIO_OFF);
    BIT_SET(GPIOB_OSPEEDR, GPIO_PIN_Med_7);
    BIT_SET(GPIOB_BSRP, GPIO_PIN_RESET_7);

}
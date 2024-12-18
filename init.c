#include "init.h"

void GPIO_Init_Self_Def(void){
    SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOBEN | RCC_AHB1ENR_GPIOCEN);

    GPIOB_MODER |= GPIOB_MODE_PIN14_OUT;         // Настройка работы 14-го пина
    GPIOB_OSPEEDR |= GPIOB_OSPEED_PIN14_MID;     // Настройка скорости

    SET_BIT(GPIOB->MODER, GPIO_MODER_MODE7_0);
    SET_BIT(GPIOB->OSPEEDR, GPIO_OSPEEDER_OSPEEDR7_0);

    SET_BIT(GPIOB->MODER, GPIO_MODER_MODE12_0);
    SET_BIT(GPIOB->OSPEEDR, GPIO_OSPEEDER_OSPEEDR12_0);

    *(uint32_t *)(0x40020400UL + 0x00UL) |= (0x1UL << 0*2);
    *(uint32_t *)(0x40020400UL + 0x08UL) |= (0x1UL << 0*2);    
}
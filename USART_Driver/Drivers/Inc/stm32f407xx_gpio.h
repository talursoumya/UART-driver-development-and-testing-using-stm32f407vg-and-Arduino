/*
 * stm32f407xx.h
 *
 *  Created on: Dec 3, 2024
 *      Author: talur
 */

#ifndef INC_STM32F407XX_GPIO_H_
#define INC_STM32F407XX_GPIO_H_

#include<stdint.h>
#include"common.h"


/*Create Generic structure for RCC Peripheral registers*/



/*peripheral register definition structure for EXTI*/
typedef struct
{
	__vo uint32_t IMR;
	__vo uint32_t EMR;
	__vo uint32_t RTSR;
	__vo uint32_t FTSR;
	__vo uint32_t SWIER;
	__vo uint32_t PR;

}EXTI_RegDef_t;

typedef struct
{

	__vo uint32_t MEMRMP;
	__vo uint32_t PMC;
	__vo uint32_t EXTICR[4];
	//__vo uint32_t EXTICR2;
	//__vo uint32_t EXTICR3;
	//__vo uint32_t EXTICR4;
	uint32_t RESERVED[2];
	__vo uint32_t CMPCR;

}SYSCFG_RegDef_t;


//some generic macros

#define ENABLE 				1
#define DISABLE 			0
#define SET 				ENABLE
#define RESET 				DISABLE
#define GPIO_PIN_SET        SET
#define GPIO_PIN_RESET      RESET
#define FLAG_RESET         RESET
#define FLAG_SET 			SET


#define GPIO_BASEADDR_TO_CODE(x) ((x==GPIOA)?0:\
		                         (x==GPIOB)?1:\
		                         (x==GPIOC)?2:\
		                         (x==GPIOD)?3:\
		                         (x==GPIOE)?4:\
		                         (x==GPIOF)?5:\
		                         (x==GPIOG)?6:\
		                         (x==GPIOH)?7:0)
/* peripheral definitions (peripheral base address typecasted to xxx_RegDef_t)*/
#define GPIOA ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF ((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG ((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH ((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define GPIOI ((GPIO_RegDef_t*)GPIOI_BASEADDR)

#define EXTI_BASEADDR    (APB2_PERIPHBASEADDR+0x3C00)
#define SYSCFG_BASEADDR  (APB2_PERIPHBASEADDR+0x3800)


/*/*Access SYSCFG peripheral registers inside SYSCFG_RegDef_t*/
#define SYSCFG            ((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)

/* Access EXTI peripheral registers inside EXTI_RegDef_t*/
#define EXTI                 ((EXTI_RegDef_t*)EXTI_BASEADDR)

/*Generic structure for GPIO register*/
typedef struct
{
	__vo uint32_t MODER;
	__vo uint32_t OTYPER;
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];

	//uint32_t AFRL;
	//uint32_t AFRH;
}GPIO_RegDef_t;


/* base address of peripheral hanging on AHB1 bus */
#define GPIOA_BASEADDR    (AHB1_PERIPHBASEADDR+0x0000)
#define GPIOB_BASEADDR    (AHB1_PERIPHBASEADDR+0x0400)
#define GPIOC_BASEADDR	  (AHB1_PERIPHBASEADDR+0x0800)
#define GPIOD_BASEADDR	  (AHB1_PERIPHBASEADDR+0x0C00)
#define GPIOE_BASEADDR	  (AHB1_PERIPHBASEADDR+0x1000)
#define GPIOF_BASEADDR	  (AHB1_PERIPHBASEADDR+0x1400)
#define GPIOG_BASEADDR	  (AHB1_PERIPHBASEADDR+0x1800)
#define GPIOH_BASEADDR	  (AHB1_PERIPHBASEADDR+0x1C00)
#define GPIOI_BASEADDR	  (AHB1_PERIPHBASEADDR+0x2000)







/* clock enable macros for GPIO peripherals*/
#define GPIOA_PCLK_EN() (RCC->AHB1ENR |= (1<<0))
#define GPIOB_PCLK_EN() (RCC->AHB1ENR |= (1<<1))
#define GPIOC_PCLK_EN() (RCC->AHB1ENR |= (1<<2))
#define GPIOD_PCLK_EN() (RCC->AHB1ENR |= (1<<3))
#define GPIOE_PCLK_EN() (RCC->AHB1ENR |= (1<<4))
#define GPIOF_PCLK_EN() (RCC->AHB1ENR |= (1<<5))
#define GPIOG_PCLK_EN() (RCC->AHB1ENR |= (1<<6))
#define GPIOH_PCLK_EN() (RCC->AHB1ENR |= (1<<7))
#define GPIOI_PCLK_EN() (RCC->AHB1ENR |= (1<<0))

/* clock enable macros for SYSCFG peripherals*/
#define SYSCFG_PCLK_EN()  (RCC->APB2ENR |= (1<<14))

/* clock disable macros for GPIO peripherals*/
/* clock disable macros for GPIO peripherals*/
#define GPIOA_PCLK_DI() (RCC->AHB1ENR &= ~(1<<0))
#define GPIOB_PCLK_DI() (RCC->AHB1ENR &= ~(1<<1))
#define GPIOC_PCLK_DI() (RCC->AHB1ENR &= ~(1<<2))
#define GPIOD_PCLK_DI() (RCC->AHB1ENR &= ~(1<<3))
#define GPIOE_PCLK_DI() (RCC->AHB1ENR &= ~(1<<4))
#define GPIOF_PCLK_DI() (RCC->AHB1ENR &= ~(1<<5))
#define GPIOG_PCLK_DI() (RCC->AHB1ENR &= ~(1<<6))
#define GPIOH_PCLK_DI() (RCC->AHB1ENR &= ~(1<<7))
#define GPIOI_PCLK_DI() (RCC->AHB1ENR &= ~(1<<0))

/*
 *  Macros to reset GPIOx peripherals
 */
#define GPIOA_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0)); }while(0)
#define GPIOB_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1)); }while(0)
#define GPIOC_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2)); }while(0)
#define GPIOD_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3)); }while(0)
#define GPIOE_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4)); }while(0)
#define GPIOF_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 5)); (RCC->AHB1RSTR &= ~(1 << 5)); }while(0)
#define GPIOG_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 6)); (RCC->AHB1RSTR &= ~(1 << 6)); }while(0)
#define GPIOH_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR &= ~(1 << 7)); }while(0)
#define GPIOI_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 8)); (RCC->AHB1RSTR &= ~(1 << 8)); }while(0)


#endif /* INC_STM32F407XX_GPIO_H_ */

#include"stm32f407xx_gpio_driver.h"

/*
 * stm32f407xx_gpio_driver.h
 *
 *  Created on: Dec 3, 2024
 *      Author: talur
 */

#ifndef INC_STM32F407XX_GPIO_DRIVER_H_
#define INC_STM32F407XX_GPIO_DRIVER_H_

#include"stm32f407xx_gpio.h"
#include<stdint.h>


typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;        /*<possible values from @GPIO_PIN_MODES>*/
	uint8_t GPIO_PinSpeed;       /*<possible values from @GPIO_PIN_POSSIBLE_SPEEDS>*/
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;


typedef struct
{
	//pointer to hold the base address of GPIO peripheral

	GPIO_RegDef_t *pGPIOx;               /*holds the address of GPIO port to which the pin belongs*/
    GPIO_PinConfig_t GPIO_PinConfig;     /*this holds GPIO pin configuration settings*/

}GPIO_Handle_t;


/*API Peripheral clock setup*/
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx,uint8_t EnorDi);



/*API Init and Deinit*/
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);

/*API Data read and write*/
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber,uint8_t value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx,uint16_t value);
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);



/* API IRQ Configuration and ISR handling*/
void GPIO_IRQInterruptConfig(uint8_t IRQNumber,uint8_t EnOrDi);
void GPIO_IRQPriorityConfig(uint8_t IRQNumber,uint32_t IRQProirity);
void GPIO_IRQHandling(uint8_t PinNumber);

/*Create GPIO pin related macros to use in functions*/
/*
 * GPIO_PinNumber
 */
#define GPIO_PIN_NO_0	 0
#define GPIO_PIN_NO_1	 1
#define GPIO_PIN_NO_2	 2
#define GPIO_PIN_NO_3	 3
#define GPIO_PIN_NO_6	 6
#define GPIO_PIN_NO_7    7
#define GPIO_PIN_NO_9	 9
#define GPIO_PIN_NO_10	 10
#define GPIO_PIN_NO_12	 12
#define GPIO_PIN_NO_13	 13
#define GPIO_PIN_NO_14	 14
#define GPIO_PIN_NO_15	 15
/*
 * GPIO pin possible modes
 */
#define GPIO_MODE_IN      0
#define GPIO_MODE_OUT     1
#define GPIO_MODE_ALTFN   2
#define GPIO_MODE_ANALOG  3
#define GPIO_MODE_IT_FT   4
#define GPIO_MODE_IT_RT   5
#define GPIO_MODE_IT_RFT  6




/*
 * GPIO_PIN_MODES
 * GPIO pin possible output types
 */
#define GPIO_OP_TYPE_PP   0
#define GPIO_OP_TYPE_OD   1

/*
 * GPIO_PIN_POSSIBLE_SPEEDS
 * GPIO pin possible output speed
 */
#define GPIO_SPEED_LOW      0
#define GPIO_SPEED_MEDIUM   1
#define GPIO_SPEED_FAST     2
#define GPIO_SPEED_HIGH     3


/*
 * GPIO pin pull up and pulldown configuration macros
 */
#define GPIO_NO_PUPD        0
#define GPIO_PU             1
#define GPIO_PD             2



#endif /* INC_STM32F407XX_GPIO_DRIVER_H_ */

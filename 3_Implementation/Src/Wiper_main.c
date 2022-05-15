#include "MyStm32f407xx.h"
#include "MyStm32f407xx.h"
#include <stdint.h>
#include <stdio.h>
#define BTN_PRESSED ENABLE

void delay(void);
void igniton_ON(void);
void igniton_OFF(void);
int wiper_ON(void);
int wiper_speed_chg_mode_1(void);
int wiper_speed_chg_mode_2(void);
void wiper_OFF(void);
void delay_4_hz(void);
void delay_8_hz(void);
uint32_t flag = 0;

int main(void)
{

	GPIO_Handle_t GpioLed, GpioLed_1, GpioLed_2, GpioLed_3, GpioBtn;


	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNo = GPIO_PIN_NO_12;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed);


	GpioLed_1.pGPIOx = GPIOD;
	GpioLed_1.GPIO_PinConfig.GPIO_PinNo = GPIO_PIN_NO_13;
	GpioLed_1.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed_1.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed_1.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed_1);


	GpioLed_2.pGPIOx = GPIOD;
	GpioLed_2.GPIO_PinConfig.GPIO_PinNo = GPIO_PIN_NO_14;
	GpioLed_2.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed_2.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed_2.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed_2);


	GpioLed_3.pGPIOx = GPIOD;
	GpioLed_3.GPIO_PinConfig.GPIO_PinNo = GPIO_PIN_NO_15;
	GpioLed_3.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed_3.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed_3.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed_3);


	GpioBtn.pGPIOx = GPIOA;
	GpioBtn.GPIO_PinConfig.GPIO_PinNo = GPIO_PIN_NO_0;
	GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&GpioBtn);

	while (1)
	{
		GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_0, DISABLE);
		if (GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0))
		{
			flag++;
		   if (flag == 1)
			{
				delay();
				igniton_ON();
				GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_RESET);
			}
		    else if(flag == 2)
			{
		    	while(flag==2){
		    		if(wiper_ON()==1){
		    			break;
		    		}
		    	}

			}
			else if(flag == 3)
			{
				while(flag==3){
					if(wiper_speed_chg_mode_1()==1){
						break;
					}
				}
			}
			else if(flag == 4)
			{
				while(flag==4){
					if(wiper_speed_chg_mode_2()==1){
						break;
					}
				}

			}
			else if(flag == 5){
				wiper_OFF();

			}
			else if(flag==6){
				delay();
				igniton_OFF();
				flag=0;
			}
		}
	}
}
void delay(void)
{
	for (uint32_t j = 0; j < 50000000; j++);
}
void delay_4_hz(void){
	for (uint32_t j = 0; j < 25000000; j++);
}
void delay_8_hz(void){
	for (uint32_t j = 0; j < 7500000; j++);
}

void igniton_ON(void)
{
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_14);
}

void igniton_OFF(void)
{
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, 0);
}
int wiper_ON(void)
{
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,0 );

	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,0 );

	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,0 );


	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,0 );

	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,0 );

	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
	delay();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,0 );

	if (GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0))
			return 1;
		else
			return 0;

}

int wiper_speed_chg_mode_1(void)
{
	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
	delay_4_hz();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,0 );

	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
	delay_4_hz();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,0 );

	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
	delay_4_hz();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,0 );

	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
	delay_4_hz();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,0 );

	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
	delay_4_hz();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,0 );

	GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
	delay_4_hz();
	GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,0 );

	if (GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0))
			return 1;
		else
			return 0;
}

int wiper_speed_chg_mode_2(void)
{
	        GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
			delay_8_hz();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,0 );

			GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
			delay_8_hz();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,0 );

			GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
			delay_8_hz();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,0 );

			GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
			delay_8_hz();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,0 );

			GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
			delay_8_hz();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,0 );

			GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
			delay_8_hz();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,0 );

			if (GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0))
					return 1;
				else
					return 0;
}


void wiper_OFF(void)
{
	        GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
			delay();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, 0);

			GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
			delay();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, 0);

			GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
			delay();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,0 );

}

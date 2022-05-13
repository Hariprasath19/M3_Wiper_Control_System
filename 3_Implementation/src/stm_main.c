#include "MyStm32f407xx.h"
#include "MyStm32f407xx.h"
#include <stdint.h>
#include <stdio.h>
#define BTN_PRESSED ENABLE

void delay(void);
void delay_speed_change_1();
void delay_speed_change_2();
void igniton_on(void);
void igniton_off(void);
int igniton_wiper_on(void);
int wiper_on(void);
int Highspeed_wiper_on();
void wiper_off(void);
uint32_t flag = 0;


int main(void)
{

	GPIO_Handle_t GpioLed, GpioLed1, GpioLed2, GpioLed3, GpioBtn;


	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed);


	GpioLed1.pGPIOx = GPIOD;
	GpioLed1.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	GpioLed1.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed1.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed1.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed1);


	GpioLed2.pGPIOx = GPIOD;
	GpioLed2.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;
	GpioLed2.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed2.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed2.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed2);


	GpioLed3.pGPIOx = GPIOD;
	GpioLed3.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;
	GpioLed3.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed3.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed3.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed3);


	GpioBtn.pGPIOx = GPIOA;
	GpioBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	GpioBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GpioBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioBtn.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&GpioBtn);

	while (1)
		{
			if (GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0)==ENABLE)
			{
		    	flag++;
				if ((flag == 1))
				{
				igniton_on();

				}
				else if ((flag == 2)){
					while(flag==2){
						if(wiper_on()==1)
						break;
					}
				}
				else if (flag == 3)
				{GPIO_WriteToOutputPin(GPIOA, GPIO_PIN_NO_0, DISABLE);
					while(flag==3){

						if(ignition_wiper_on()==1)
							break;

						}
				}
				else if (flag == 4){
								while(flag==4){
									if(Highspeed_wiper_on()==1)
										break;
									}
							}
				else if (flag == 5)
				{
					wiper_off();
				    igniton_off();
				}
				else {
				igniton_off();
				}
			}
		}
	}
	void delay(void)
	{
		for (uint32_t i = 0; i < 50000000; i++);
	}
	void delay_speed_change_1(void){
		for (uint32_t i = 0; i < 25000000; i++);
	}
	void delay_speed_change_2(void){
		for (uint32_t i = 0; i < 7500000; i++);
	}
	void igniton_on(void)
	{
		delay();
		delay();
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_14);
	}

	void igniton_off(void)
	{   delay();
	    delay();
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, 0);
	}
	int ignition_wiper_on(void)
	{
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
		delay_speed_change_1();
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,0 );

		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
		delay_speed_change_1();
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,0 );

		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
		delay_speed_change_1();
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,0 );

		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
		delay_speed_change_1();
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,0 );

		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
		delay_speed_change_1();
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,0 );

		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
		delay_speed_change_1();
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,0 );

		if (GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0))
			return 1;
		else
			return 0;
	}
	int wiper_on(void)
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

	void wiper_off(void)
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
	int Highspeed_wiper_on(void)
	{
		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
		delay_speed_change_2();
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,0 );

		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
		delay_speed_change_2();
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,0 );

		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
		delay_speed_change_2();
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,0 );

		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_13);
		delay_speed_change_2();
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13,0 );

		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
		delay_speed_change_2();
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12,0 );

		GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_15);
		delay_speed_change_2();
		GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15,0 );

		if (GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0))
			return 1;
		else
			return 0;
	}

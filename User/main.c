#include "stm32f4xx.h"
#include "Lab2_Test.h"

/*
#define green GPIO_Pin_12;
#define red GPIO_Pin_14);
#define blue GPIO_Pin_15;
#define yellow GPIO_Pin_13;
*/
uint16_t var;
uint32_t answer = 0;
	
uint8_t Lab2_Test_ini(char *name);
uint32_t read_flag(void);
void onlyBlueLEDon (void);
void onlyGreenLEDon (void);
void onlyRedLEDon (void);
void onlyYellowLEDon (void);

int main(void)
{
	uint32_t i;
	
	var = Lab2_Test_ini("Petrunin");
	//read_flag();
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	
	GPIO_InitTypeDef PORT_init_struct;
	
	PORT_init_struct.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15 ;;
	PORT_init_struct.GPIO_Mode = GPIO_Mode_OUT;
	PORT_init_struct.GPIO_Speed = GPIO_Speed_2MHz;
	PORT_init_struct.GPIO_OType = GPIO_OType_PP;
	PORT_init_struct.GPIO_PuPd = GPIO_PuPd_NOPULL;

	GPIO_Init(GPIOD, &PORT_init_struct);

	while(1)
	{		
		GPIO_SetBits(GPIOD, GPIO_Pin_14);	
		for (i=0;i<3000000;i++) {}
		GPIO_ResetBits(GPIOD, GPIO_Pin_14);	
		GPIO_SetBits(GPIOD, GPIO_Pin_12);		
		for (i=0;i<3000000;i++) {}
		GPIO_ResetBits(GPIOD, GPIO_Pin_12);	
		GPIO_SetBits(GPIOD, GPIO_Pin_15);	
		for (i=0;i<3000000;i++) {}
		GPIO_ResetBits(GPIOD, GPIO_Pin_15);	
		GPIO_SetBits(GPIOD, GPIO_Pin_12);	
		for (i=0;i<3000000;i++) {}
		GPIO_ResetBits(GPIOD, GPIO_Pin_12);	
		GPIO_SetBits(GPIOD, GPIO_Pin_13);		
		for (i=0;i<3000000;i++) {}
		GPIO_ResetBits(GPIOD, GPIO_Pin_13);	
		GPIO_SetBits(GPIOD, GPIO_Pin_15);		
		for (i=0;i<3000000;i++) {}
		GPIO_ResetBits(GPIOD, GPIO_Pin_15);	
		GPIO_SetBits(GPIOD, GPIO_Pin_14);		
		for (i=0;i<3000000;i++) {}
		GPIO_ResetBits(GPIOD, GPIO_Pin_14);	
		GPIO_SetBits(GPIOD, GPIO_Pin_13);		
		for (i=0;i<3000000;i++) {}
		GPIO_ResetBits(GPIOD, GPIO_Pin_13);
		
		answer = read_flag();					
	}
}


/*int main(void)
{
	var = Lab2_Test_ini("uno");
	read_flag();
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	
	GPIO_InitTypeDef GPIO_struct_LED; // задание структуры, описывающей инициализацию нужных портов

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE); // включение тактирования порта I/O E
	
	GPIO_struct_LED.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15 ;
	GPIO_struct_LED.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_struct_LED.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_struct_LED.GPIO_OType = GPIO_OType_PP;
	GPIO_struct_LED.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(GPIOD, &GPIO_struct_LED);
	
	while(1)
	{
		for (i=0;i<3000000;i++) {}
		onlyRedLEDon ();
		for (i=0;i<3000000;i++) {}
		onlyGreenLEDon ();
		for (i=0;i<3000000;i++) {}
		onlyBlueLEDon ();
		for (i=0;i<3000000;i++) {}
		onlyGreenLEDon ();
		for (i=0;i<3000000;i++) {}
		onlyYellowLEDon ();
		for (i=0;i<3000000;i++) {}
		onlyBlueLEDon ();
		for (i=0;i<3000000;i++) {}
		onlyRedLEDon ();
		for (i=0;i<3000000;i++) {}
		onlyYellowLEDon ();
		for (i=0;i<3000000;i++) {}
		answer = read_flag();
	}
}

void onlyYellowLEDon (void)
{
	GPIO_ResetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
	GPIO_SetBits(GPIOD, GPIO_Pin_13);	
	return;
}

void onlyBlueLEDon (void)
{
	GPIO_ResetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
	GPIO_SetBits(GPIOD, GPIO_Pin_15);	
	return;
}

void onlyRedLEDon (void)
{
	GPIO_ResetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
	GPIO_SetBits(GPIOD, GPIO_Pin_14);	
	return;
}

void onlyGreenLEDon (void)
{
	GPIO_ResetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
	GPIO_SetBits(GPIOD, GPIO_Pin_12);	
	return;
}*/


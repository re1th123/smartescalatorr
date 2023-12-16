#include "TM4C123.h"    // Device header

#define LCD GPIOB    		//
LCD port with Tiva C 
#define RS 0x01				 	//RS -> PB0 (0x01)
#define RW 0x02         //RW -> PB1 (0x02)
#define EN 0x04  		 	 	//EN -> PB2 (0x04)


void HC05_init(void); // Initialize UART5 module for HC-05
char Bluetooth_Read(void); //Read data from Rx5 pin of TM4C123

void Bluetooth_Write(unsigned char data); // Transmit a character to HC-05 over Tx5 pin 
void Bluetooth_Write_String(char *str); // Transmit a string to HC-05 over Tx5 pin 



void Delay(void);
 
 


//Functions Declaration
void delayUs(int);   														   //Delay in Micro Seconds
void delayMs(int);   														   //Delay in Milli Seconds
void LCD4bits_Init(void);													 //Initialization of LCD Dispaly
void LCD_Write4bits(unsigned char, unsigned char); //Write data as (4 bits) on LCD
void LCD_WriteString(char*);											 //Write a string on LCD 
void LCD4bits_Cmd(unsigned char);									 //Write command 
void LCD4bits_Data(unsigned char);								 //Write a character
void detect(void);
void ndetect(void);


int main(void)
{
	SYSCTL->RCGCGPIO = 0x07;


	 GPIOC->DEN =0X10;
	 GPIOB->DEN =0XFF;
	 
	GPIOA->DEN=0X00000004;
  

		GPIOC->DIR =0X00;
		GPIOA->DIR=0X00000004;
		GPIOB->DIR =0XFF;
		
		GPIOC->PUR=0X10;
	
		HC05_init(); // call HC05_init() to initialze UART5 of TM4C123GH6PM
	
	/* Set PF1, PF2 and PF3 as digital output pins */
	
		SYSCTL->RCGCGPIO |= 0x20;   /* enable clock to GPIOF */
    GPIOF->DIR |= 0x0E;         //set PF1, PF2 and PF3 as digital output pin
    GPIOF->DEN |= 0x0E;        
		while(1){
			
				char c = Bluetooth_Read(); 
				if (c =='S'){

				char* str1 = "    MOTION   ";    //Write any string you want to display on LCD
				LCD4bits_Init();									//Initialization of LCD
				LCD4bits_Cmd(0x01);								//Clear the display
																					//Force the cursor to beginning of 1st line
				delayMs(500);											//delay 500 ms for LCD (MCU is faster than LCD)
				LCD_WriteString(str1);							//Write the string on LCD
				delayMs(500);											//Delay 500 ms to let the LCD diplays the data
		
				
				if((GPIOC->DATA & 0x10)==0)
				{
					
					detect();
					
					
					
					}
					else
					{
						ndetect();
						
						
					}}
				
		
				else{
					GPIOF->DATA |=(1<<3);
					delayMs(500);
					GPIOF->DATA &=~(1<<3);
					
					
					}
					
				
				}	
	
			}

void detect(void)
{
				char* str2 = "  		DETECTED ";    //Write any string you want to display on LCD
				LCD4bits_Init();									//Initialization of LCD
				LCD4bits_Cmd(0x01);								//Clear the display
				LCD4bits_Cmd(0xC0);               //Force the cursor to beginning of 1st line
				GPIOC->DATA |= 0x10;										//delay 500 ms for LCD (MCU is faster than LCD)
				LCD_WriteString(str2);
				//Write the string on LCD
				GPIOF->DATA |=(1<<1);
				GPIOA->DATA |= 	GPIOA->DATA| (1<<2);
					delayMs(500);
					GPIOA->DATA &= 	(~(1<<2));
				GPIOF->DATA &=~(1<<1);
				//Delay 500 ms to let the LCD diplays the data
}
void ndetect(void)
{
   char* str2 = " 	NOT DETECTED ";    //Write any string you want to display on LCD
				LCD4bits_Init();									//Initialization of LCD
				LCD4bits_Cmd(0x01);								//Clear the display
				LCD4bits_Cmd(0xC0);               //Force the cursor to beginning of 1st line
				delayMs(500);											//delay 500 ms for LCD (MCU is faster than LCD)
				LCD_WriteString(str2);							//Write the string on LCD
				delayMs(500);		
				GPIOF->DATA |=(1<<3);
					delayMs(500);
					GPIOF->DATA &=~(1<<3);

	//Delay 500 ms to let the LCD diplays the data
}


void LCD4bits_Init(void)
{
	SYSCTL->RCGCGPIO |= 0x02;    //enable clock for PORTB
	delayMs(10);                 //delay 10 ms for enable the clock of PORTB
  LCD->DIR = 0xFF;             //let PORTB as output pins
	LCD->DEN = 0xFF;             //enable PORTB digital IO pins
	LCD4bits_Cmd(0x28);          //2 lines and 5x7 character (4-bit data, D4 to D7)
	LCD4bits_Cmd(0x06);          //Automatic Increment cursor (shift cursor to right)
	//LCD4bits_Cmd(0x01);					 //Clear display screen
	LCD4bits_Cmd(0x0F);
	//Display on, cursor blinking
}


void LCD_Write4bits(unsigned char data, unsigned char control)
{
	data &= 0xF0;                       //clear lower nibble for control 
	control &= 0x0F;                    //clear upper nibble for data
	LCD->DATA = data | control;         //Include RS value (command or data ) with data 
	LCD->DATA = data | control | EN;    //pulse EN
	delayUs(0);													//delay for pulsing EN
	LCD->DATA = data | control;					//Turn off the pulse EN
	LCD->DATA = 0;                      //Clear the Data 
}

void LCD_WriteString(char * str)
{  
	volatile int i = 0;          //volatile is important 
	
	while(*(str+i) != '\0')       //until the end of the string
	{
		LCD4bits_Data(*(str+i));    //Write each character of string
		i++;                        //increment for next character
	}
}

void LCD4bits_Cmd(unsigned char command)
{
	LCD_Write4bits(command & 0xF0 , 0);    //upper nibble first
	LCD_Write4bits(command << 4 , 0);			 //then lower nibble
	
	if(command < 4)
		delayMs(2);       //commands 1 and 2 need up to 1.64ms
	else
		delayUs(40);      //all others 40 us
}

void LCD4bits_Data(unsigned char data)
{
	LCD_Write4bits(data & 0xF0 , RS);   //upper nibble first
	LCD_Write4bits(data << 4 , RS);     //then lower nibble
	delayUs(40);												//delay for LCD (MCU is faster than LCD)
}

void delayMs(int n)
{  
	volatile int i,j;             //volatile is important for variables incremented in code
	for(i=0;i<n;i++)
		for(j=0;j<3180;j++)         //delay for 1 msec
		{}
}

void delayUs(int n)             
{
	volatile int i,j;							//volatile is important for variables incremented in code
	for(i=0;i<n;i++)
		for(j=0;j<3;j++)            //delay for 1 micro second
		{}
}
void HC05_init(void)
{
	SYSCTL->RCGCUART |= 0x20;  /* enable clock to UART5 */
    SYSCTL->RCGCGPIO |= 0x10;  /* enable clock to PORTE for PE4/Rx and RE5/Tx */
    delayUs(1);
															/* UART0 initialization */
    UART5->CTL = 0;         /* UART5 module disbable */
    UART5->IBRD = 104;      /* for 9600 baud rate, integer = 104 */
    UART5->FBRD = 11;       /* for 9600 baud rate, fractional = 11*/
    UART5->CC = 0;          /*select system clock*/
    UART5->LCRH = 0x60;     /* data lenght 8-bit, not parity bit, no FIFO */
    UART5->CTL = 0x301;     /* Enable UART5 module, Rx and Tx */

    /* UART5 TX5 and RX5 use PE4 and PE5. Configure them digital and enable alternate function */
    GPIOE->DEN = 0x30;      /* set PE4 and PE5 as digital */
    GPIOE->AFSEL = 0x30;    /* Use PE4,PE5 alternate function */
    GPIOE->AMSEL = 0;    /* Turn off analg function*/
    GPIOE->PCTL = 0x00110000;     /* configure PE4 and PE5 for UART */
}
char Bluetooth_Read(void)  
{
    char data;
	  while((UART5->FR & (1<<4)) != 0); /* wait until Rx buffer is not full */
		//data = UART5->DR;
		
		
		data = 'S'; 
				/* before giving it another byte */
    return (unsigned char) data; 
}

void Bluetooth_Write(unsigned char data)  
{
    while((UART5->FR & (1<<5)) != 0); /* wait until Tx buffer not full */
    UART5->DR = data;                  /* before giving it another byte */
}

void Bluetooth_Write_String(char *str)
{
  while(*str)
	{
		Bluetooth_Write(*(str++));
	}
}
#define DELAY_VALUE        40000000   

void Delay(void)
{
	volatile unsigned long i;
	for(i=0;i<DELAY_VALUE;i++);
}
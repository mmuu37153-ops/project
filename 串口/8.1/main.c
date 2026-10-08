#include <REGX52.H>
#include "Delay.h"
#include "Uart.h"

unsigned char sec;

void main()
{
	UartInit();
	while(1)
	{
		//UART_SendByte(sec);
		//sec++;
		//Delay(1000);
	}
}


void UartInt() interrupt 4
{
	if(RI==1)
	{
		P2=SBUF;
		UART_SendByte(SBUF);
		RI=0;
	}
} 
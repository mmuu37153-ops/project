#include <REGX52.H>


void UartInit(void)		//4800bps@11.0592MHz
{
	SCON = 0x50;			//方式1，允许接收
	PCON &= 0x7F;			//不倍数
	TMOD &= 0x0F;			//0000 1111
	TMOD |= 0x20;		//0010 0000
	TL1 = 0xFA;		//设定定时初值
	TH1 = 0xFA;		//设定定时器重装值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
}

void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;
	while(TI==0);
	TI=0;
}
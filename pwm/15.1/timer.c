#include <REGX52.H>


void Timer0Init0(void)		//0.1毫秒
{
	TMOD &= 0xF0;		//清零T0位
	TMOD |= 0x01;		//T0 设置为模式1（16位定时器）
	TL0 = 0xA4;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	TF0 = 0;
	TR0 = 1;
	EA = 1;				//开启总中断
	ET0  = 1;			//开启定时器0中断
}


void Timer0Init1(void)		//1毫秒@12.000MHz
{
	TMOD &= 0x0F;	
	TMOD |= 0x20;	
	TL1 = 0xD0;
	TH1 = 0xFF;
	TR1 = 0;
	EA = 1;	
	ET1 = 0;	
}


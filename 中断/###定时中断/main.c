#include <REGX52.H>
#include "timer.h"


void main()
{
	Timer0Init0();
	Timer0Init1();
	
	while(1)
	{
		
	}
}

void timer0() interrupt 1
{
	static int i = 0;
	
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	
	i++;
	if (i==1000)
	{
		i=0;
		P2_0=~P2_0;
	}
}

void timer2() interrupt 3
{
	static int i = 0;
	
	TL1 = 0x0C;		//设置定时初值
	TH1 = 0xFE;		//设置定时初值
	
	i++;
	if (i==1000)
	{
		i=0;
		P2_1=~P2_1;
	}
}

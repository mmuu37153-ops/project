#include <REGX52.H>
#include "Delay.h"
#include "Nixie.h"
#include "timer.h"

sbit LED1=P2^0;
sbit Motor=P1^0;

unsigned char Counter,Compare;
unsigned char Speed;

void main()
{
	
	
	Timer0Init0();
	Compare=10;
	while(1)
	{
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0)
			Delay(20);
			Speed++;
			Speed%=4;
			if(Speed==3){Compare=0;}
			if(Speed==2){Compare=20;}
			if(Speed==1){Compare=50;}
			if(Speed==0){Compare=100;}
		}
		Nixie(1,Speed);
	}
}


void Timer0() interrupt 1
{
	TL0 = 0xA4;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	Counter++;
	Counter%=100;
	if (Counter<Compare)
	{
		Motor=0;
	}
	else
	{
		Motor=1;
	}
}
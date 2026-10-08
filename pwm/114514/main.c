#include <REGX52.H>
#include "Delay.h"
#include "Nixie.h"
#include "timer.h"

sbit LED1=P2^0;
sbit sg90=P2^1;

unsigned char Counter,Compare;
unsigned char Speed;

void main()
{
	Speed=8;
	
	Timer0Init0();
	Compare=15;
	while(1)
	{
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			if (Speed<10) Speed++;
			
			if(Speed==9){Compare=16;}
			if(Speed==8){Compare=15;}
			if(Speed==7){Compare=14;}
			if(Speed==6){Compare=13;}
			if(Speed==5){Compare=12;}
			if(Speed==4){Compare=11;}
			if(Speed==3){Compare=10;}
			if(Speed==2){Compare=9;}
			if(Speed==1){Compare=8;}
			if(Speed==0){Compare=7;}
		}
		if(P3_0==0)
		{
			Delay(20);
			while(P3_0==0);
			Delay(20);
			if (Speed>0) Speed--;

			if(Speed==9){Compare=16;}
			if(Speed==8){Compare=15;}
			if(Speed==7){Compare=14;}
			if(Speed==6){Compare=13;}
			if(Speed==5){Compare=12;}
			if(Speed==4){Compare=11;}
			if(Speed==3){Compare=10;}
			if(Speed==2){Compare=9;}
			if(Speed==1){Compare=8;}
			if(Speed==0){Compare=7;}
		}
		Nixie(1,Speed);
	}
}


void Timer0() interrupt 1
{
	TL0 = 0xA4;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	Counter++;
	Counter%=200;
	if (Counter<Compare)
	{
		sg90=1;
	}
	else
	{
		sg90=0;
	}
}
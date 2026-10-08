#include <REGX52.H>
#include "delay.h"

void exti0()
{
EA=1;
EX0=1;
IT0=1;
}

void exti1()
{
EA=1;
EX1=1;
IT1=1;
}



void main()
{
	exti0();
	exti1();
	while(1)
	{
		
	}
}

void ext0() interrupt 0
{
	Delay(10);
	if (P3_3==0)
	{
	P2_0=~P2_0;
	}
}

void ext1  () interrupt 2
{
	Delay(10);
	if (P3_3==0)
	{
	P2_1=0;
	Delay(500);
	}
	P2_1=1;
}
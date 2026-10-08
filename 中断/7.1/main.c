#include <REGX52.H>

void Delay(unsigned char xms)		//@12.000MHz
{
	unsigned char i, j;

	while(xms)
	{
	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
	xms--;
	}
}

unsigned char flag0=0;
unsigned char flag1=0;


void ex0(void)
{
	EA=1;
	IT0=1;
	EX0=1;
}

void ex0int() interrupt 0
{
	if (P3_2==0)
	{
		flag0=1;
		flag1=0;
	}
}

void ex1(void)
{
	EA=1;
	IT1=1;
	EX1=1;
}

void ex1int() interrupt 2
{
	if (P3_3==0)
	{
		flag1=1;
		flag0=0;
	}
}


void main()
{
	void timer0();
	unsigned char a=0x01;
	P2=~a;
	ex0();
	ex1();
	while(1)
	{
		if (flag0==1)
		{
				
				P2=~a;
				Delay(100);
				if (a==0x01) a=0x80;
				else a=a>>1;
				
		}
		
		if (flag1==1)
		{
				
				P2=~a;
				Delay(100);
				if (a==0x80) a=0x01;
				else a=a<<1;
				
		}
	}
}

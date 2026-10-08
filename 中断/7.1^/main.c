#include <REGX52.H>

unsigned char flag0=0;
unsigned char flag1=1;
unsigned char tcount0=0;
unsigned char tcount1=0;
unsigned char a = 0x01;

void timer0(void)
{
	TMOD &= 0xF0;
	TMOD |= 0x01;
	TL0 = 0x18;
	TH0 = 0xFC;
	TF0=0;
	ET0=1;
	TR0=0;
}

void timer1(void)
{
	TMOD &= 0x0F;
	TMOD |= 0x10;
	TL1 = 0x18;
	TH1 = 0xFC;
	TF1=0;
	ET1=1;
	TR1=0;
}

void ex0(void)
{
	IT0=1;
	EX0=1;
}

void ex1(void)
{
	IT1=1;
	EX1=1;
}


void main()
{
	EA=1;
	P2=~a;
	timer0();
	timer1();
	ex0();
	ex1();
	while(1)
	{
		if (flag0==1)
		{
				TR0=1;
				TR1=0;
				
		}
		
		else if (flag1==1)
		{
				
			TR0=0;
			TR1=1;
			
		}
	}
}



void timer0int() interrupt 1
{
	tcount0++;
	if(tcount0>=100)
	{
		P2=~a;
		tcount0=0;
		if (a==0x01) a=0x80;
		else a=a>>1;
	}
	
	TL0 = 0x18;
	TH0 = 0xFC;
}


void timer1int() interrupt 3
{
	tcount1++;
	if(tcount1>=100)
	{
		tcount1=0;
		P2=~a;
		if (a==0x80) a=0x01;
		else a=a<<1;
	}
	
	TL1 = 0x18;
	TH1 = 0xFC;
}


void ex0int() interrupt 0
{
		flag0=1;
		flag1=0;
}



void ex1int() interrupt 2
{
		flag1=1;
		flag0=0;
}



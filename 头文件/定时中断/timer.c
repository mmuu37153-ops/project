#include <REGX52.H>

//默认关闭TR，请手动打开

void Timer0Init(void)		//100微秒@11.0592MHz
{
	TMOD &= 0xF0;		//清零T0位
	TMOD |= 0x01;		//T0 设置为模式1（16位定时器）
	TL0 = 0xA4;
	TH0 = 0xFF;
	TF0 = 0;
	TR0 = 0;
	EA = 1;				//开启总中断
	ET0  = 1;			//开启定时器0中断
}


void Timer1Init(void)		//100微秒@11.0592MHz
{
	TMOD &= 0x0F;		//清零T1位
	TMOD |= 0x10;		//T1 设置为模式1（16位定时器）
	TL1 = 0xA4;
	TH1 = 0xFF;
	TF1 = 0;
	TR1 = 0;
	EA = 1;				//开启总中断
	ET0  = 1;			//开启定时器0中断
}

/*中断函数
void timer0() interrupt 1
{
	
	TL0 = 0xA4;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	}
}
*/
#include <REGX52.H>


void ex0(void)
{
	EA=1;
	IT0=1;
	EX0=1;
}


void ex1(void)
{
	EA=1;
	IT1=1;
	EX1=1;
}

/*中断函数
void ex0int() interrupt 0
{
	
}
*/
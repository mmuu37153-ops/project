#include <REGX52.H>
#include "Delay.h"




void main()
{
	unsigned char LedNum;
	LedNum=0;
	P2=~0x01;
	while(1)
	{
		if (P3_1==0)
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			LedNum++;
			if (LedNum>=8)
			{
				LedNum=0;
			}
			P2=~(0x01<<LedNum);

		}
		if (P3_0==0)
		{
			Delay(20);
			while(P3_0==0);
			Delay(20);
			if (LedNum==0)
			{
				LedNum=7;
			}
			else
				LedNum--;
			P2=~(0x01<<LedNum);
			
		}
	}
}
#include <REGX52.H>
#include "Delay.h"


/**
 * @brief  获取独立按键键码
 * @param  无
 * @retval 按下按键的键码，范围：0~4，无按键按下时返回值为0
 */
 
unsigned char Key(void)
{
	unsigned char KeyNumber=0;

	if(P3^1==0){Delay(20);while(P3^1==0);Delay(20);KeyNumber=1;}
	if(P3^0==0){Delay(20);while(P3^0==0);Delay(20);KeyNumber=2;}
	if(P3^2==0){Delay(20);while(P3^2==0);Delay(20);KeyNumber=3;}
	if(P3^3==0){Delay(20);while(P3^3==0);Delay(20);KeyNumber=4;}

	return KeyNumber;
}

//unsigned char KeyNum;
//Key=KeyNum;
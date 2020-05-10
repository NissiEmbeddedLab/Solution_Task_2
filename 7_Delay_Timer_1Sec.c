#include<reg51.h>
void T0M1Delay(unsigned int x);   //how many times you need to run by this argument
void main(void)
{
	while(1)
	{
			P1 = 0x0F;
			T0M1Delay(50); 							// 50x10msec = 1000msec or 1sec if you want to 2sec replace 100 by 200
			P1 = ~P1;
			T0M1Delay(50);
	}
}
void T0M1Delay(unsigned int x) 		//function to create 10msec delay 
{
	unsigned int a;
	for(a=0;a<x;a++)
	{
	TMOD = 0x01;
	TH0 = 0xD8; 										//0XD8F0 FOR 10msec delay @12MHz Oscillator frquency
	TL0 = 0xF0;
	TR0 = 1;
	while(TF0 == 0);
	TR0 = 0;
	TF0 = 0;
	}
}
#include "stm32f4xx.h"
#include "usart.h"
#include "delay.h"
#include "esp8266.h"

#define DelayTime 30

//STM32F4工程模板-库函数版本
//淘宝店铺：http://mcudev.taobao.com

float fData[]={24.3,22.6,15.4,26.7,22.2,36.1,25.3,56.1,45.2,87.2,62.3,41.5,21.3,33.2,65.3};
int iData[]={895,745};

void data_Report(void);

void delayMinute(){
	int i=0;
	for(i=0;i<2;i++)
	  delay_ms(1000);
}

int main(void)
{
	u32 t=0;
	
	delay_init(84);
	delay_ms(5000);
	uart_init(115200);
	delay_ms(5000);
  while(!bConfirmed){
    if(CheckUsartStatus())
			getTimeCount();
		//delay_ms(500);
	}
	while(1)
	{
		data_Report();
		
		delayMinute();
	}
}

void data_Report(void)
{
	delay_ms(DelayTime);
  assemble(TimeCount,1,1,fData[0]);
	delay_ms(DelayTime);
	assemble(TimeCount,2,1,fData[1]);
	delay_ms(DelayTime);
	assemble(TimeCount,3,1,fData[2]);
	delay_ms(DelayTime);
	assemble(TimeCount,4,1,fData[3]);
	delay_ms(DelayTime);
	assemble(TimeCount,5,1,fData[4]);
	delay_ms(DelayTime);
	assemble(TimeCount,6,1,fData[5]);
	delay_ms(DelayTime);
	assemble(TimeCount,7,1,fData[6]);
	delay_ms(DelayTime);
	assemble(TimeCount,8,1,fData[7]);
	delay_ms(DelayTime);
	assemble(TimeCount,9,1,fData[8]);
	delay_ms(DelayTime);
	assemble(TimeCount,10,1,fData[9]);
	delay_ms(DelayTime);
	assemble(TimeCount,11,1,fData[10]);
	delay_ms(DelayTime);
	assemble(TimeCount,12,1,fData[11]);
	delay_ms(DelayTime);
	assemble(TimeCount,13,1,fData[12]);
	delay_ms(DelayTime);
	assemble(TimeCount,14,1,fData[13]);
	delay_ms(DelayTime);
	assemble(TimeCount,15,1,fData[14]);
	delay_ms(DelayTime);
	assemble(TimeCount,16,0,iData[0]);
	delay_ms(DelayTime);
	assemble(TimeCount,17,0,iData[1]);
	delay_ms(DelayTime);
	TimeCount++;
}



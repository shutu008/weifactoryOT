#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "esp8266.h"
#include "usart.h"

u8 DeviceNum[] = "ZWGC2017100800003";
u8 TCPConnected[] = "TCP connected";
long long TimeCount = 0;
int bConfirmed = 0;

typedef struct ResolvedData
{
    int num;
    int type;
    int iData;
    float fData;
    char str[40];
}ResolvedData;

void assemble(long long time,int num,int type,...)
{
    char str[20];
    char *s;
    int iData;
    double fData;
    va_list ls;
    va_start(ls,type);
    switch(type)
    {
    case 0:iData=va_arg(ls,int);sprintf(str,"#%s#%d#%d#%d#%lld$",DeviceNum,num,type,iData,time);break;
    case 1:fData=va_arg(ls,double);sprintf(str,"#%s#%d#%d#%.2f#%lld$",DeviceNum,num,type,fData,time);break;
    case 2:s=va_arg(ls,char*);sprintf(str,"#%s#%d#%d#%s#%lld$",DeviceNum,num,type,s,time);break;
    default:break;
    }
    printf("%s",str);
    va_end(ls);
}

struct ResolvedData resolve(char str[])
{
    struct ResolvedData getStruct;
    sscanf(str,"#%d#%d#",&getStruct.num,&getStruct.type);
    switch (getStruct.type) {
    case 0:
        sscanf(str,"#%d#%d#%d#",&getStruct.num,&getStruct.type,&getStruct.iData);
        break;
    case 1:
        sscanf(str,"#%d#%d#%f#",&getStruct.num,&getStruct.type,&getStruct.fData);
        break;
    case 2:
        sscanf(str,"#%d#%d#%s#",&getStruct.num,&getStruct.type,getStruct.str);
    default:
        break;
    }
    return getStruct;
}

int CheckUsartStatus(void)
{
	if(USART_RX_STA&0x8000)
		return 1;
	return 0;
}

void getTimeCount(void)
{
	//printf("%s",USART_RX_BUF);
	/*USART_RX_STA = 0;
	if(strcmp(TCPConnected, USART_RX_BUF) == 0)
	{
		//printf("correct\r\n");
		bConfirmed = 1;
	}
	if(bConfirmed)
	{
	while(!CheckUsartStatus());*/
	sscanf(USART_RX_BUF,"%lld\r\n",&TimeCount);
	bConfirmed = 1;
	//printf("%lld\r\n",TimeCount);
	//}
}


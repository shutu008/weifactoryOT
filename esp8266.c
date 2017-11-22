#include <stdio.h>
#include <stdarg.h>
#include "esp8266.h"
#include "usart.h"

static char DeviceID[]="ZWGC2017100800007";
long long TimeCount = 0;
long long TimeSet = 0;

typedef struct ResolvedData
{
    char type[40];//类型
    int reserved;//扩展字段（保留）
    int ID;//控制机构ID
    int state;//开关状态
    long long time;//执行时间
}ResolvedData;

void UpLoadData(long long time,int num,int type,...)
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
    sscanf(str,"#%s#%d#%d#%d%lld#$",&getStruct.type,&getStruct.reserved,&getStruct.ID,&getStruct.state,&getStruct.time);
    return getStruct;
}

void UpLoadImage(char Image[],long length)
{
    t=0;
	a=0;b=200;
	printf("#%s#",DeviceID);
	while(!CheckUsartStatus());
	USART_RX_STA = 0;
	while(t<length)
	{
	    for(t=a;t<b;t++)
	    {
		    while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
		    USART_SendData(USART1, pic[t]);
	    }
	a+=200;
	b+=200;
	if(b>=length)
		b=length;
	while(!CheckUsartStatus());
	USART_RX_STA = 0;
	}
}
